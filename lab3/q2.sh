#!/bin/sh

echo "Which folder would you like to check"
read folder
echo "Enter pattern to match"
read pattern
x=`find $folder -type f -iname "*$pattern*"`
for i in $x;do
echo "$i"
done
