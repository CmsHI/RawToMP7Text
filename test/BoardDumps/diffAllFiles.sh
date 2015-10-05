#!/bin/bash
for N in 01 02 03 04 05 06 07 08 09 10
do
    EMULATOR="../EmulatorOutput/HI_Central_Data_${N}_emulatorOutput.txt"
    FIRMWARE="flippedBits.out/HI_Central_Data_${N}_tx_summary.txt"
    diff $EMULATOR $FIRMWARE
done
