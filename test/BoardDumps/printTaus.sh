#!/bin/bash
cat $1 | awk '{ print $54 " " $55 }' | grep 1v
