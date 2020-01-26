#!/bin/bash

[ ! -f courses.txt ] && echo "One or more files do not exist" && exit 1
[ ! -f names.txt ] && echo "One or more files do not exist" && exit 1

if [[ $1 == "-count" ]]
then
	echo "-count works"
elif [[ $1 == "-f" ]]
then
	echo "-f"	
elif [[ $1 == "-g" ]]
then
	echo "-g"
elif [[ $1 == "-c" ]]
then
	echo "-c"
elif [[ $1 == "-list" ]]
then
	echo "-list"
fi

exit 1
