"""
This cfg file uses the RCT emulator to produce RCT digis which are arranged into
the bitfields for the oRSC optical links, which are output to two text files to
be loaded on two oRSCs.

Author: D. Austin Belknap, UW-Madison
"""

import FWCore.ParameterSet.Config as cms

process = cms.Process("ORSCPATTERNS")

process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff')
from Configuration.AlCa.GlobalTag_condDBv2 import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, 'auto:run1_data', '')

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(1000)
    )

process.source = cms.Source(
    "PoolSource",
    fileNames = cms.untracked.vstring(
        "/store/user/icali/HIMinBiasUPC/HIMinBiasUPC_Skim_HLT_HIMinBiasHfOrBSC_v2/35880fcf9fb9fd84b27cd1405e09ffd1/SD_MinBiasHI_1006_1_l3z.root"
    )
    )

process.load("Configuration.Geometry.GeometryIdeal_cff")

#process.load('EventFilter.L1TRawToDigi.caloStage1Digis_cfi')
#process.caloStage1Digis.InputLabel = cms.InputTag("rawDataRepacker")

process.gctDigis = cms.EDProducer("GctRawToDigi",
    checkHeaders = cms.untracked.bool(False),
    gctFedId = cms.untracked.int32(745),
    hltMode = cms.bool(False),
    inputLabel = cms.InputTag("rawDataRepacker"),
    numberOfGctSamplesToUnpack = cms.uint32(5),
    numberOfRctSamplesToUnpack = cms.uint32(1),
    unpackSharedRegions = cms.bool(False),
    unpackerVersion = cms.uint32(0),
    verbose = cms.untracked.bool(True)
)
process.patterns = cms.EDAnalyzer('OrscLinkPatterns',
                                  src = cms.InputTag("gctDigis"),
                                  outputFile = cms.string("rx_summary.txt"))

process.pattern_sequence = cms.Sequence(
    #process.caloStage1Digis
    process.gctDigis
    +process.patterns)

process.p = cms.Path(process.pattern_sequence)
