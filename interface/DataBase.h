#ifndef _DATABASE_h
#define _DATABASE_h

#include <iostream>
#include <stdexcept>
#include <vector>
#include <stdint.h>


class DataBase {
  private:
  
  int RCEt_start [7][2];  //card, region
  int RCTau_start[7][2];  //card, region
  int RCOf_start[7][2];   //card, region
  int HFEt_start[8];      //region
  int HFFg_start[8];      //region
  int IEEt_start[4];      //candidate
  int IEPos_start[4];     //candidate
  int NEEt_start[4];      //candidate
  int NEPos_start[4];     //candidate
  int RCHad_start[7][2];  //card, region
     
  int RCETlength;
  int RCTaulength;
  int RCOflength;
  int HFEtlength;
  int HFFglength;
  int IEEtlength;
  int IEPoslength;
  int NEEtlength;
  int NEPoslength;
  int RCHadlength;

  int RCETlink;
  int RCTaulink;
  int RCOflink;
  int HFEtlink;
  int HFFglink;
  int IEEtlink;
  int IEPoslink;
  int NEEtlink;
  int NEPoslink; 
  int RCHadlink;

  public:
    DataBase();
    ~DataBase(){};
    

    int GetRCEtLength(){return RCETlength;};
    int GetRCTauLength(){return RCTaulength;};
    int GetRCOfLength(){return RCOflength;};
    int GetHFEtLength(){return HFEtlength;};
    int GetHFFgLength(){return HFFglength;};
    int GetIEEtLength(){return IEEtlength;};
    int GetIEPosLength(){return IEPoslength;};
    int GetNEEtLength(){return NEEtlength;};
    int GetNEPosLength(){return NEPoslength;};
    int GetRCHadLength(){return RCHadlength;};

    int GetRCEtLink(){return RCETlink;};
    int GetRCTauLink(){return RCTaulink;};
    int GetRCOfLink(){return RCOflink;};
    int GetHFEtLink(){return HFEtlink;};
    int GetHFFgLink(){return HFFglink;};
    int GetIEEtLink(){return IEEtlink;};
    int GetIEPosLink(){return IEPoslink;};
    int GetNEEtLink(){return NEEtlink;};
    int GetNEPosLink(){return NEPoslink;};
    int GetRCHadLink(){return RCHadlink;};
      
    int GetIndicesRCEt(int card, int region) { return RCEt_start[card][region];}
    int GetIndicesRCTau(int card, int region){ return RCTau_start[card][region];}
    int GetIndicesRCOf(int card, int region) { return RCOf_start[card][region];}
    int GetIndicesHFEt(int region) { return HFEt_start[region];}
    int GetIndicesHFFg(int cand) { return HFFg_start[cand];}
    int GetIndicesIEEt(int cand) { return IEEt_start[cand];}
    int GetIndicesIEPos(int cand){ return IEPos_start[cand];}
    int GetIndicesNEEt(int cand) { return NEEt_start[cand];}
    int GetIndicesNEPos(int cand){ return NEPos_start[cand];}
    int GetIndicesRCHad(int card, int region){ return RCHad_start[card][region];}

};

#endif
