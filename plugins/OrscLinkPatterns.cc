/**
 * Filename: OrscLinkPatterns.cc
 *
 * Description: This producer creates 18 "OrscLinks" objects (one for each RCT
 *              crate). It then loops over the Regions and EM Candidates from
 *              the RCT emulator and loads them into the OrscLink objects. The
 *              optical link layout of the bits are extracted from the OrscLink
 *              objects and loaded into a single text file.
 *
 * Author: D. Austin Belknap, UW-Madison
 */

// system include files
#include <memory>
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include "stdint.h"

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Utilities/interface/EDGetToken.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "DataFormats/L1CaloTrigger/interface/L1CaloCollections.h"
#include "DataFormats/L1CaloTrigger/interface/L1CaloRegion.h"
#include "DataFormats/L1CaloTrigger/interface/L1CaloEmCand.h"
#include "DataFormats/L1CaloTrigger/interface/L1CaloRegionDetId.h"

#include "../interface/CaloLinks.h"


class OrscLinkPatterns : public edm::EDAnalyzer {
  public :
    explicit OrscLinkPatterns(const edm::ParameterSet&);
    ~OrscLinkPatterns();


  private:
    virtual void beginJob();
    virtual void analyze(const edm::Event&, const edm::EventSetup&);
    virtual void endJob();

    std::vector<L1CaloRegionCollection> vectorcaloregioncollection;
    std::vector<L1CaloEmCollection> vectorEMcollection;

    edm::Handle<L1CaloRegionCollection> newRegions;
    edm::Handle<L1CaloEmCollection> newEMCands;

    std::ofstream outfile;
    std::string outputName;

    void addRegion(CrateLinks& crateLink, const L1CaloRegion &reg);
    void addEM(CrateLinks& crateLink, const L1CaloEmCand &cand);

    edm::EDGetToken regionToken;
    edm::EDGetToken candsToken;


    int eventcounter;
};

OrscLinkPatterns::OrscLinkPatterns(const edm::ParameterSet& iConfig) {
  regionToken = consumes<L1CaloRegionCollection>(iConfig.getParameter<edm::InputTag>("src"));
  candsToken = consumes<L1CaloEmCollection>(iConfig.getParameter<edm::InputTag>("src"));
  outputName = iConfig.getParameter<std::string>("outputFile");

}


OrscLinkPatterns::~OrscLinkPatterns() {
}


void
OrscLinkPatterns::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup) {
  using std::cout;
  using std::endl;

  using namespace edm;

  // Grab Region and EM collections
  iEvent.getByToken(regionToken, newRegions);
  iEvent.getByToken(candsToken, newEMCands);

  // std::string outname = "";
  // outname += "InputsoRSC/output_";
  // outname += Form("%d",iEvent.id().event());
  // outname += ".txt";
  // outfile.open(outname.c_str(), std::ofstream::out);

  // Load each region into the OrscLink object of its crate

  vectorcaloregioncollection.push_back(*newRegions);
  vectorEMcollection.push_back(*newEMCands);
  eventcounter++;
}


void
OrscLinkPatterns::beginJob() {
  outfile.open(outputName, std::ofstream::out);
  eventcounter=0;
}


void
OrscLinkPatterns::endJob() {

  //if(eventcounter<9) std::cout<<"ERROR: number of events less than 9. It wont be possible to read 2x1 regions"<<std::endl;

  CaloLinks calolinkMerged(0,0,0);
  std::cout<<"numer of events"<<eventcounter<<std::endl;

  for(int indexevent=0;indexevent<eventcounter+9;indexevent++){

    if(indexevent<eventcounter){
      for (L1CaloRegionCollection::const_iterator mynewRegion = vectorcaloregioncollection[indexevent].begin();
	   mynewRegion != vectorcaloregioncollection[indexevent].end(); mynewRegion++) {
        addRegion(calolinkMerged.get_crate(mynewRegion->rctCrate()), *mynewRegion);
      }
    }

    if(indexevent>=9){
      for (L1CaloEmCollection::const_iterator myegtCand = vectorEMcollection[indexevent-9].begin();
	   myegtCand != vectorEMcollection[indexevent-9].end(); myegtCand++) {
	addEM(calolinkMerged.get_crate(myegtCand->rctCrate()), *myegtCand);
      }
    }
    calolinkMerged.write_to_file(outfile);
  }
  outfile.close();
}


void
OrscLinkPatterns::addRegion(CrateLinks& crateLink, const L1CaloRegion &reg) {
  unsigned card   = reg.rctCard();
  unsigned region = reg.rctRegionIndex();
  unsigned et     = reg.et();
  unsigned rctPhi = reg.rctPhi();
  unsigned rctEta = reg.rctEta();
  //unsigned gctPhi = reg.gctPhi();
  //unsigned gctEta = reg.gctEta();

  bool tau        = reg.tauVeto();
  bool mip        = reg.mip();
  bool overflow   = reg.overFlow();
  bool finegrain  = reg.fineGrain();

  bool isHF       = reg.isHf();

  if (isHF) {
    // std::cout << " regionIndex: " << region
    // 	      << " rctPhi: " << rctPhi
    // 	      << " rctEta7: " << rctEta-7 << std::endl;
    crateLink.set_HFFg(rctPhi, rctEta-7, finegrain & 0x1);

    for (int i = 0; i < 8; ++i) {
      crateLink.set_HFEt(rctPhi, rctEta-7, i, et & 0x1);
      et >>= 1;
    }
  }
  else {
    crateLink.set_RCOf(card, region, overflow & 0x1);
    crateLink.set_RCTau(card, region, tau & 0x1);
    crateLink.set_RCHad(card, region, mip & 0x1);

    // separate the 10 region bits
    for (int i = 0; i < 10; ++i) {
      crateLink.set_RCEt(card, region, i, et & 0x1);
      et >>= 1;
    }
  }
}

/**
 * Add a L1CaloEmCand and parse the bits
 */
void
OrscLinkPatterns::addEM(CrateLinks& crateLink, const L1CaloEmCand &cand) {
  unsigned index = cand.index();
  unsigned card = cand.rctCard();
  unsigned region = cand.rctRegion();
  unsigned rank = cand.rank();
  bool iso = cand.isolated();

  // Separate and store the 6 rank bits, 3 card bits, region bit, for iso and
  // non-iso EM candidates.
  if (!iso) {
    for (int i = 0; i < 6; ++i) {
      crateLink.set_NEEt(index, i, rank & 0x1);
      rank >>= 1;
    }

    crateLink.set_NEPos(index, 0, region & 0x1);
    for (int i = 1; i < 4; ++i) {
      crateLink.set_NEPos(index, i, card & 0x1);
      card >>= 1;
    }
  }
  else {
    for (int i = 0; i < 6; ++i) {
      crateLink.set_IEEt(index, i, rank & 0x1);
      rank >>= 1;
    }

    crateLink.set_IEPos(index, 0, region & 0x1);
    for (int i = 1; i < 4; ++i) {
      crateLink.set_IEPos(index, i, card & 0x1);
      card >>= 1;
    }
  }
}


DEFINE_FWK_MODULE(OrscLinkPatterns);
