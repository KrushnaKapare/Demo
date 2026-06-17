#!/bin/bash

num=10

# for (( i = 1 ; i < 11 ; i++ ))
# for i in 1 2 3 4 5 6 7 8 9 10
for i in `seq 10`
do
	echo `expr $num \* $i`
done


























