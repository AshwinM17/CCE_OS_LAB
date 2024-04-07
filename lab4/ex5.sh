function_name () {
echo "hello from  a function"
retval=0
return "$retval"

echo "The previous function has a return value of $?"
retval=$?
