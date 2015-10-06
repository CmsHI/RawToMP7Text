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
    #'/store/user/icali/HIMinBiasUPC/HIMinBiasUPC_Skim_HLT_HIMinBiasHfOrBSC_Centrality0-10//64ca16868e481177958780733023cfa2/SD_MB_Cen0_10_166_1_NpX.root'
    #"file:/afs/cern.ch/work/g/ginnocen/public/FilesForUnpackers/skim_10_1_wd2.root"

# # 1
# '/store/user/icali/HIMinBiasUPC/HIMinBiasUPC_Skim_HLT_HIMinBiasHfOrBSC_Centrality0-10//64ca16868e481177958780733023cfa2/SD_MB_Cen0_10_100_1_cwZ.root',
# '/store/user/icali/HIMinBiasUPC/HIMinBiasUPC_Skim_HLT_HIMinBiasHfOrBSC_Centrality0-10//64ca16868e481177958780733023cfa2/SD_MB_Cen0_10_101_1_Y8q.root',
# '/store/user/icali/HIMinBiasUPC/HIMinBiasUPC_Skim_HLT_HIMinBiasHfOrBSC_Centrality0-10//64ca16868e481177958780733023cfa2/SD_MB_Cen0_10_102_1_Tmr.root',

#     #2
# '/store/user/icali/HIMinBiasUPC/HIMinBiasUPC_Skim_HLT_HIMinBiasHfOrBSC_Centrality0-10//64ca16868e481177958780733023cfa2/SD_MB_Cen0_10_103_1_8aJ.root',
# '/store/user/icali/HIMinBiasUPC/HIMinBiasUPC_Skim_HLT_HIMinBiasHfOrBSC_Centrality0-10//64ca16868e481177958780733023cfa2/SD_MB_Cen0_10_104_1_aye.root',

    ## 3
# '/store/user/icali/HIMinBiasUPC/HIMinBiasUPC_Skim_HLT_HIMinBiasHfOrBSC_Centrality0-10//64ca16868e481177958780733023cfa2/SD_MB_Cen0_10_105_1_Muz.root',
# '/store/user/icali/HIMinBiasUPC/HIMinBiasUPC_Skim_HLT_HIMinBiasHfOrBSC_Centrality0-10//64ca16868e481177958780733023cfa2/SD_MB_Cen0_10_106_1_c2m.root',

    ## 4
# '/store/user/icali/HIMinBiasUPC/HIMinBiasUPC_Skim_HLT_HIMinBiasHfOrBSC_Centrality0-10//64ca16868e481177958780733023cfa2/SD_MB_Cen0_10_107_1_96s.root',
# '/store/user/icali/HIMinBiasUPC/HIMinBiasUPC_Skim_HLT_HIMinBiasHfOrBSC_Centrality0-10//64ca16868e481177958780733023cfa2/SD_MB_Cen0_10_108_1_xnb.root',

    ## 5
# '/store/user/icali/HIMinBiasUPC/HIMinBiasUPC_Skim_HLT_HIMinBiasHfOrBSC_Centrality0-10//64ca16868e481177958780733023cfa2/SD_MB_Cen0_10_109_1_NWe.root',
# '/store/user/icali/HIMinBiasUPC/HIMinBiasUPC_Skim_HLT_HIMinBiasHfOrBSC_Centrality0-10//64ca16868e481177958780733023cfa2/SD_MB_Cen0_10_10_1_0tY.root',

    ## 6
# '/store/user/icali/HIMinBiasUPC/HIMinBiasUPC_Skim_HLT_HIMinBiasHfOrBSC_Centrality0-10//64ca16868e481177958780733023cfa2/SD_MB_Cen0_10_110_1_fkm.root',
# '/store/user/icali/HIMinBiasUPC/HIMinBiasUPC_Skim_HLT_HIMinBiasHfOrBSC_Centrality0-10//64ca16868e481177958780733023cfa2/SD_MB_Cen0_10_112_1_sHP.root',

    ## 7
# '/store/user/icali/HIMinBiasUPC/HIMinBiasUPC_Skim_HLT_HIMinBiasHfOrBSC_Centrality0-10//64ca16868e481177958780733023cfa2/SD_MB_Cen0_10_114_1_K2E.root',
# '/store/user/icali/HIMinBiasUPC/HIMinBiasUPC_Skim_HLT_HIMinBiasHfOrBSC_Centrality0-10//64ca16868e481177958780733023cfa2/SD_MB_Cen0_10_115_1_h4h.root',

    ## 8
# '/store/user/icali/HIMinBiasUPC/HIMinBiasUPC_Skim_HLT_HIMinBiasHfOrBSC_Centrality0-10//64ca16868e481177958780733023cfa2/SD_MB_Cen0_10_120_1_RnI.root',
# '/store/user/icali/HIMinBiasUPC/HIMinBiasUPC_Skim_HLT_HIMinBiasHfOrBSC_Centrality0-10//64ca16868e481177958780733023cfa2/SD_MB_Cen0_10_121_1_2Fu.root',
# '/store/user/icali/HIMinBiasUPC/HIMinBiasUPC_Skim_HLT_HIMinBiasHfOrBSC_Centrality0-10//64ca16868e481177958780733023cfa2/SD_MB_Cen0_10_122_1_wlm.root',

    ## 9
# '/store/user/icali/HIMinBiasUPC/HIMinBiasUPC_Skim_HLT_HIMinBiasHfOrBSC_Centrality0-10//64ca16868e481177958780733023cfa2/SD_MB_Cen0_10_123_1_soE.root',
# '/store/user/icali/HIMinBiasUPC/HIMinBiasUPC_Skim_HLT_HIMinBiasHfOrBSC_Centrality0-10//64ca16868e481177958780733023cfa2/SD_MB_Cen0_10_124_1_p5Y.root',

    ## 10
#'/store/user/icali/HIMinBiasUPC/HIMinBiasUPC_Skim_HLT_HIMinBiasHfOrBSC_Centrality0-10//64ca16868e481177958780733023cfa2/SD_MB_Cen0_10_126_1_pCl.root',
#'/store/user/icali/HIMinBiasUPC/HIMinBiasUPC_Skim_HLT_HIMinBiasHfOrBSC_Centrality0-10//64ca16868e481177958780733023cfa2/SD_MB_Cen0_10_128_1_FuJ.root',
    "file:/afs/cern.ch/work/r/richard/public/HI_L1_FirmwareTesting/Mismatched_HI_Jets_RAW.root"

)
options.maxEvents = 100
options.parseArguments()

process = cms.Process("ORSCPATTERNS")

process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff')
from Configuration.AlCa.GlobalTag_condDBv2 import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, 'auto:run2_data', '')

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(options.maxEvents)
    )

process.source = cms.Source(
    "PoolSource",
    fileNames = cms.untracked.vstring(options.inputFiles)
    )

process.load("Configuration.Geometry.GeometryIdeal_cff")
process.load("L1Trigger.L1TCalorimeter.L1TCaloStage1_PPFromRaw_cff")
#process.load("L1Trigger.L1TCalorimeter.L1TCaloStage1_HIFromRaw_cff")
process.load('L1Trigger.L1TCalorimeter.caloStage1RCTLuts_cff')
process.caloStage1Params.jetSeedThreshold = cms.double(0.)
process.RCTConfigProducers.eicIsolationThreshold = cms.uint32(7)
process.RCTConfigProducers.hOeCut = cms.double(999)
process.RCTConfigProducers.eMinForHoECut = cms.double(999)
process.RCTConfigProducers.eMaxForHoECut = cms.double(999)
process.RCTConfigProducers.hMinForHoECut = cms.double(999)
process.RCTConfigProducers.eMinForFGCut = cms.double(999)


process.patterns = cms.EDAnalyzer('OrscLinkPatterns',
                                  src = cms.InputTag("simRctDigis"),
                                  outputFile = cms.string("InputsoRSC/Mismatched_HI_Jets_rx.txt"))

process.pattern_sequence = cms.Sequence(
    #process.L1TRerunHCALTP_FromRAW
    process.hcalDigis
    +process.ecalDigis
    +process.simRctDigis
    +process.patterns)

process.p = cms.Path(process.pattern_sequence)
