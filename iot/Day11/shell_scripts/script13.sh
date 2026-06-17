#!/bin/bash

# Array

arr=(11 22 33 44 55)

echo "arr = ${arr[*]}"
echo "length = ${#arr[*]}"

i=0
while [ $i -lt 5 ]
do
	echo "arr[$i] = ${arr[$i]}"
	i=`expr $i + 1`
done

























