#!/bin/bash

echo "Enter the text file"
read file

line_no=1
while IFS= read -r line;do
if [ "$((line_no%2))" -eq 1 ]; then
echo "$line" >> temp
fi
((line_no++))
done<"$file"

mv temp "$file"

echo "Even numbered lines deleted"

