#!/bin/bash

# package installation script

packages=(vim gcc valgrind g++ rename ncal net-tools)

echo "updating sources list ..."
sudo apt-get update
if [ $? -ne 0 ]
then
	echo "sources list is not updated ???"
	exit
fi
echo "sources list is updated !!!"

for pkg in ${packages[*]}
do
	echo "$pkg is installing ..."
	sudo apt-get install $pkg
	if [ $? -ne 0 ]
	then
		echo "$pkg is not installed ???"
	fi
	echo "$pkg is installed !!!"
done


























