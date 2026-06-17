#!/bin/bash

# find area of circle

echo -n "Enter radius of circle : "
read r

area=`echo "3.142 * $r * $r" | bc`
echo "area of circle = $area"

























