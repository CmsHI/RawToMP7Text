#!/bin/bash
#i=$2
#cat $1 | awk '{print $4}'

while read -r -a line
do
    flip1=$((0x${line[0]}))
    flip2=$((0x${line[1]}))
    flip3=$((0x${line[2]}))
    flip4=$((0x${line[3]}))
    let "nflip1=$flip1 | $((0x8000))"
    let "nflip2=$flip2 | $((0x8000))"
    let "nflip3=$flip3 | $((0x8000))"
    let "nflip4=$flip4 | $((0x8000))"
    printf "%x %x %x %x\n" $nflip1 $nflip2 $nflip3 $nflip4
    #printf "%x \n" $nflip1
done < $1
