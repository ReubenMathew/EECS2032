#!/bin/bash

cont=1
read -p "" curr

while : 
do	
	last=$curr
	read -p "" curr

	if [[ $curr -lt 0 ]]
	then
		if [[ $cont == 1 ]] 
		then
			echo "YES"
		else
			echo "NO"
		fi

		exit 0
	fi	

	diff=$(( $curr - $last ))
	if [[ $diff != 1 ]]
	then
		#echo "bad"
		cont=0
	fi
done
