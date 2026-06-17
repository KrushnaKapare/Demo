#!/bin/bash

# function

#	method1
#		function func_name
#		{
#			...
#		}

#	method2
#		func_name()
#		{
#			...
#		}

# function parameters are accessed like positional parameters

print()
{
	echo "parameter = $1"
}

function sum
{
	# op1 - $1
	# op2 - $2
	res=`expr $1 + $2`
	echo $res
}

print 10
print sunbeam
print 3.142
s=`sum 10 20`
echo "s = $s"





















