#!/bin/bash
cat $1 | awk '{ print $46 " " $47 " " $48 " " $49 }' | grep 1v
