#!/bin/bash

echo "Enter a number"
read no

fact=1

for((i=1;i <= no; i++));do
fact=$((fact*i))
done

echo "The factorial is $fact"
