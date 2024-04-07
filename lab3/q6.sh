#!/bin/bash

for file in *;do
if [ -f "$file" ];then
sed -i -E 's/(^|\.)ex:/\1Exammple:/g' "$file"
fi
done

echo "File modified"
