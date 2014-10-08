"""
This cfg file uses the RCT emulator to produce RCT digis which are arranged into
the bitfields for the oRSC optical links, which are output to two text files to
be loaded on two oRSCs.

Author: D. Austin Belknap, UW-Madison
"""

import FWCore.ParameterSet.Config as cms

from FWCore.ParameterSet.VarParsing import VarParsing
options = VarParsing('analysis')

options.inputFiles = (
    '/store/user/icali/HIMinBiasUPC/HIMinBiasUPC_Skim_HLT_HIMinBiasHfOrBSC_Centrality0-10//64ca16868e481177958780733023cfa2/SD_MB_Cen0_10_100_1_cwZ.root'
    #'file:/export/d00/scratch/luck/L1EmulatorTestInput.root'
    #'file:/afs/cern.ch/work/g/ginnocen/public/skim_10_1_wd2.root'
)
options.maxEvents = 100
options.parseArguments()

process = cms.Process("ORSCPATTERNS")

process.load('Configuration/StandardSequences/FrontierConditions_GlobalTag_cff')
#process.GlobalTag.globaltag = 'POSTLS161_V12::All'
process.GlobalTag.globaltag = 'GR_P_V27A::All'

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(options.maxEvents)
    )

process.source = cms.Source(
    "PoolSource",
    fileNames = cms.untracked.vstring(options.inputFiles)
    )

process.load("Configuration.Geometry.GeometryIdeal_cff")
#process.load("L1Trigger.L1TCalorimeter.L1TCaloStage1_PPFromRaw_cff")
process.load("L1Trigger.L1TCalorimeter.L1TCaloStage1_HIFromRaw_cff")

process.patterns = cms.EDAnalyzer('OrscLinkPatterns',
                                  src = cms.InputTag("simRctDigis"),
                                  outputFile = cms.string("InputsoRSC/output_51events_HI.txt"))

process.pattern_sequence = cms.Sequence(
    #process.L1TRerunHCALTP_FromRAW
    process.hcalDigis
    +process.ecalDigis
    +process.simRctDigis
    +process.patterns)

process.p = cms.Path(process.pattern_sequence)
