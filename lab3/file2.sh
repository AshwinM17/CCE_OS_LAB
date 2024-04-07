#Control statements

#if
read character
if [ "$character" = "2" ]; then
echo " You entered two."
fi

#if else
read fileName
if [ -e $fileName ]; then
echo "File $fileName exists"
else
echo "File $fileName does not exist"
fi

#elseif ladder
read a b
if [ $a == $b ]; then
echo "$a is equal to $b"
elif [ $a -gt $b ]; then
echo "$a is greater than $b"
elif (( a<b)) ; then
echo "$a is less than $b"
else
echo "None of the condition met"
fi

#for
echo "enter loop time"
read n
for (( i=1; i<=n; i++));do
echo -n $i
done

# for each
IFS=$’\n'
x=`ls -l | cut -c 1`
for i in $x;do
if [ $i = "d" ] ; then
echo "This is the directory $i"
fi
done

# while 
echo "Enter number of times"
read n
i=1;
while (( i <= n)); do
echo -n $i " "
((i++))
done
echo "done"

#until
echo "enter numer of times"
read n
i=1
until (( i > n )); do
echo -n $i " "
((i++))
done

# exit
echohi
echo "last error status $?"
exit $? 
echo "HI"

#switch case
echo -n "Enter a number 1 or string Hello or character A"
read character
case $character in
1) echo "You entered one.";;
"Hello") echo -n "You entered two" echo "Yoo another line";
'A') echo "You entered A";;
*) echo "Rrebel"
esac
