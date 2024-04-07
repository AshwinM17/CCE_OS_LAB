#!/bin/bash

echo "Enter the basic salary"
read basic
echo "Enter the TA"
read TA
GA=$(echo "$basic + $TA + 0.01*$basic"|bc -l)
echo "$GA"
