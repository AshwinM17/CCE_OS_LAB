#!/bin/bash

x=`find . -type f -iname "*.txt"`
for i in $x;do
j=`echo "$i" | cut -d '.' -f 2` 
echo $j
mv $i  ./$j.text
done
