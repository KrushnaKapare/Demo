#!/bin/bash

# file conditionals

#	-e $path	- true if path exists
#	-f $file	- true if file is regular
#	-d $file	- true if file is directory
#	-x $file	- true if file has execute permission
#	-r $file	- true if file has read permission
#	-w $file	- true if file has write permission

echo -n "Enter path : "
read path

if [ -e $path ]
then
	if [ -f $path ]
	then 
		cat $path
	elif [ -d $path ]
	then
		ls $path
	fi
else
	echo "$path doesn't exist"
fi

























