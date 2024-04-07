#!/bin/bash

echo "Enter the text file"
read file

even_file="evenfile"
odd_file="oddfile"

line_no=1
while IFS= read -r line;do
if [ "$((line_no%2))" -eq 0 ]; then
echo "$line" >> "$even_file"
else
echo "$line" >> "$odd_file"
fi
((line_no++))
done<"$file"

echo "Even and odd numbered lines transferres"

