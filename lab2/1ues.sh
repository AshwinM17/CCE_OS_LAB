file=$1
x=`wc -l <  $file`
y=`wc -w <  $file`
echo "lines: $x             words: $y "
