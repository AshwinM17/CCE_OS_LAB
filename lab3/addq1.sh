#!/bin/bash

echo "Enter a number"
read no

is_prime=true

if [ "$no" -lt 2 ]; then
is_prime=false
else
for((i=2; i <=$((no/2)); i++));do
if [ $((no % i)) -eq 0 ];then
is_prime=false
break
fi
done
fi

if [ "$is_prime" = true ];then
echo "$no is prime"
else
echo "$no is not prime"
fi
