#!/bin/sh

echo "Deleteing the following files"

for file in "$@";do
echo "$file"
rm -i "$file"
done

echo "All files deleted successfully"
