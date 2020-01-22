#!/bin/bash

x=$1
y=$2
z=$3
w=$4

for (( i = 1;  i <= $x; i++ ))
do
	for (( j = 1; j <= $y; j++ ))
	do
		for (( k = 1; k <= $z; k++ ))
		do
			for (( l = 1; l <= $w; l++))
			do
				first=$((i**3 + j**3))
				second=$((k**3 + l**3))
				#echo $first $second
				if (( $first == $second ))
				then
					#echo "x= "$i", y= "$j", z= "$k", w= "$l
					#if ! (( $i == $k && $j == $l )) 
					#then	
					#	if ! (( $i == $l && $j == $k  ))
					#	then	
						#echo $first $second
							echo "x= "$i", y= "$j", z= "$k", w= "$l
					#	fi	
					#fi 
				fi
			done
		done
	done
done



