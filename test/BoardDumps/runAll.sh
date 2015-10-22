#!/bin/bash

set -x

mkdir -p cleaned.out
mkdir -p flippedBits.out

for realFileBase in zeros nominal left alternate
do

    file=/afs/cern.ch/work/r/richard/public/HI_L1_FirmwareTesting/patternTests/HI_Central_Data_${realFileBase}/100ppEvtOutput.txt
    #realFileBase=nominal

    for object in "Jets" "Egammas" "Taus" "Centrality"
    do
	mkdir -p print${object}.out
	realFile="${realFileBase}_${object}.txt"
	./print${object}.sh $file > print${object}.out/${realFile}
	sed 's/1v0000//g' print${object}.out/${realFile} > cleaned.out/$realFile
	if [[ $object == "Jets" || $object == "Egammas" ]]
	then
	    ./removeFlippingBits.sh cleaned.out/$realFile > flippedBits.out/$realFile
	elif [[ $object == "Taus" ]]
	then
	    ./removeFlippingBits_taus.sh cleaned.out/$realFile > flippedBits.out/$realFile
	else
	    ./cleanCentrality.sh cleaned.out/$realFile > flippedBits.out/${realFile}
	fi
    done
done
