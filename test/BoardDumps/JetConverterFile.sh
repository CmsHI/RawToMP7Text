#!/bin/bash
pt1=0
eta1=0
phi1=0
sign1=0
pt2=0
eta2=0
phi2=0
sign2=0
lindex=0
while read -r -a line
do
    var1=$((0x${line[0]}))
    var2=$((0x${line[1]}))

    let "pt1= var1&$((0x3F))"
    let "eta1=(var1>>6)&$((0x7))"
    let "sign1=(var1>>9)&$((0x1))"
    let "phi1=(var1>>10)&$((0x1F))"
    let "pt2= var2&$((0x3F))"
    let "eta2=(var2>>6)&$((0x7))"
    let "sign2=(var2>>9)&$((0x1))"
    let "phi2=(var2>>10)&$((0x1F))"

    echo "------------------"
    printf "%x\n" $var1
    echo pt=$pt1
    echo eta=$eta1
    echo phi=$phi1
    echo sign=$sign1
    echo "------------------"
    printf "%x\n" $var2
    echo pt=$pt2
    echo eta=$eta2
    echo phi=$phi2
    echo sign=$sign2
    if [ $((lindex%2)) -eq 1 ]
    then
        echo "------------------"
    fi
    let lindex=lindex+1


done < $1
