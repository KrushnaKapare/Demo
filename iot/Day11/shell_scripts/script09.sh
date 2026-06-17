#!/bin/bash

#	loops

#	initialization
#	while [ condition ]					#	true - body executes
#	do									#	false - loop terminates
#		...
#		modification
#	done


#	initialization
#	until [ condition ]					#	false - body executes
#	do									#	true - loop terminates
#		...
#		modification
#	done


#	for(( init ; cond ; mod ))
#	do
#		...
#	done


#	for variable in collection
#	do
#		...
#	done

num=10

echo "Table of $num : "

i=1
# while [ $i -lt 11 ]
until [ $i -eq 11 ]
do
	echo `expr $num \* $i`
	i=`expr $i + 1`
done























