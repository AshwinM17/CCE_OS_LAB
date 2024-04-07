#!/bin/bash

echo "Enter the name of item to be checked"
read name
if [ -f $name ]; then
echo "File $name exists"
elif [ -d $name ]; then
echo "Directory $name exists"
else
echo "Neither file or directory"
fi
