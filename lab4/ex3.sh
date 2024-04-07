declare arrayOfNumber
j=0
for i in $@
do
arrayOfNumber[j]=$i
((j++))
done
echo "${arrayOfNumber[@]}"
