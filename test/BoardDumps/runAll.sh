#!/bin/bash

mkdir -p printJets.out
mkdir -p cleaned.out
mkdir -p flippedBits.out
mkdir -p jetConverter.out

for file in algoHI_1_1_2/HI_Central_Data_*tx_summary.txt
do
    realFile=$(basename ${file})
    ./printJets.sh $file > printJets.out/${realFile}
    sed 's/1v0000//g' printJets.out/${realFile} > cleaned.out/$realFile
#    cat cleaned.out/$realFile | ./removeFlippingBits.sh > flippedBits.out/$realFile
    #    cat flippedBits.out/$realFile | ./JetConverterFile.sh > jetConverter.out/$realFile
    ./removeFlippingBits.sh cleaned.out/$realFile > flippedBits.out/$realFile
    ./JetConverterFile.sh flippedBits.out/$realFile > jetConverter.out/$realFile
done
