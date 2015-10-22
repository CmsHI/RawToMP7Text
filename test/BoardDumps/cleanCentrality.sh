#!/bin/bash

cat $1 | awk ' NR%2 {print "print(int(str(bin(0x"$1"))[3:6],2))"}' > file.py
python file.py
rm file.py
