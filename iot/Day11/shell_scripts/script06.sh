#!/bin/bash

#	if [ condition ]
#	then
#		...
#	fi

#	if [ condition ]
#	then
#		...
#	else
#		...
#	fi

#	if [ condition ]
#	then
#		...
#	elif [ condition ]
#	then
#		...
#	else
#		...
#	fi

# relational operators
#		-lt, -gt, -le, -ge, -eq, -ne

# logical operators
#		-a, -o, !

# find maximum of two numbers

echo -n "Enter two numbers : "
read n1 n2

max=0
if [ $n1 -eq $n2 ]
then
	echo "n1 and n2 are equal"
	max=$n1
elif [ $n1 -gt $n2 ]
then
	echo "n1 is maximum"
	max=$n1
else
	echo "n2 is maximum"
	max=$n2
fi

echo "maximum value : $max"



























