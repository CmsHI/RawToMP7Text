#!/bin/bash
cat $1 | awk '{ print $42 " " $43 " " $44 " " $45 }' | grep 1v
