#!/bin/bash

dir=$1
filename=$2
path="$dir/$filename"

#echo $path

if [[ $# -ne 2 ]]
then
	echo "usage: sh1.sh dir file" && exit 1
fi

if [[ ! -d $dir ]]
then 
	echo "$dir is not a directory"
fi

if [[ -d $2 ]]
then
	echo "$filename is not a regular file" && exit 1
fi

if [[ -f $path ]]
then
	echo "file $2 is in $dir" && exit 1
else 
	echo "file $2 is not in $dir" && exit 1
fi
