#!/bin/bash
cat $1 | awk '{ print $52 }' | grep 1v
