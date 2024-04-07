read -a inputArrayOfNumbers
echo -n "Entered input is..."
for i in ${inputArrayOfNumbers[@]} ; do
echo -n $i " "
done
