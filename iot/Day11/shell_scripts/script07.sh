#!/bin/bash

# string conditionals

#	str1 = str2		- true if str1 and str2 are equal
#	str1 != str2	- true if str1 and str2 are not equal
#	-z str			- true if str is empty
#	-n str			- true if str is not empty

str=nitin

if [ -z $str ]
then
	echo "string is empty"
else
	r_str=`echo $str | rev`
	echo "str = $str"
	echo "r_str = $r_str"
	if [ $str = $r_str ]
	then
		echo "string is palindrome"
	else
		echo "string is not palindrome"
	fi
fi

























