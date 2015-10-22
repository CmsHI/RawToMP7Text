#!/bin/bash
#set -x
string="s/${2}//g"
grep $2 -A2 --no-group-separator $1 | sed $string > $2_grepped.out
diff -w -B $2_grepped.out $3
