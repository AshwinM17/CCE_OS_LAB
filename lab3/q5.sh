#!/bin/bash

echo "Enter the file extension"
read ext

echo "Enter the destination folder"
read dest

mkdir -p "$dest"

files=$(find . -maxdepth 1 -type f -name "*.$ext")
for file in $files; do
    cp "$file" "$dest"
done

echo "Successfully copied files"
