RawToMP7Text
============

This is a combination of three previous projects:
* https://github.com/uwcms/oRSCPatterns
* https://github.com/uwcms/CaloLinks/tree/newformat
* https://github.com/ginnocen/ConvertedoRSCtoMP7

The purpose is to turn any event in a RAW file into a text format suitable for running on MP7 hardware. To use it, follow the directions at https://twiki.cern.ch/twiki/bin/view/CMSPublic/SWGuideL1TOfflineDev to set up an emulator env. Then, follow these directions:

```sh
cd $CMSSW_BASE/src
git clone git@github.com:CmsHI/RawToMP7Text.git L1Trigger/RawToMP7Text
scram build -j4
cd L1Trigger/RawToMP7Text
make
cd test
cmsRun makeOrscLinkPatterns.py #makes a file named output.txt
./testGlobal # turns output.txt into output_mp7.txt
```

The file output_mp7.txt can then be given to a firmware developer.
