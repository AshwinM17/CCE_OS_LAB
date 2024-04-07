#Basic arithmetic expressions

#expr
echo "Enter a value"
read a 
a=$(expr $a + 1)
echo "$a"
a=`expr $a + 1`
echo "$a"

#test[]
echo "Enter Two Values"
read a b
result=$[ a -eq b ]
echo "Check for Equality $result"

#test(())
echo "Enter two values"
read a b
echo "Enter operator(+,-,/,%,*)"
read op
((a++))
result=$((a $op b))
echo "Result of performing $a $op $b is $result"

#bc
echo "Enter two values"
read a b
echo "Enter the operator(+,-,/,%,*)"
read op
result=`bc -l<<<$a\$op$b`
#or result=`echo "$a $op $b"|bc -l`
echo "Result of $a $op $b is $result"
