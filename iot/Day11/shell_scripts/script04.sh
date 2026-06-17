#!/bin/bash

# find area of rectangle

echo "Enter length and breadth : "
read le br

# command substitution
#	command is substituted by its result
#	method1 :	`command`
#	method2 :	$(command)

area=`expr $le \* $br`
echo "area of rectangle = $area"


























