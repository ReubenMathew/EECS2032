#!/bin/bash

[ ! -f courses.txt ] && echo "One or more files do not exist" && exit 1
[ ! -f names.txt ] && echo "One or more files do not exist" && exit 1

if [[ $1 == "-count" ]]
then
	n=`grep -c ^ names.txt`
	n=$((n))
	echo "$n"
elif [[ $1 == "-f" ]]
then
	id=0
	while read line;do
		name=`echo "$line" | cut -d $'\t' -f1`
		temp_id=`echo "$line" | cut -d $'\t' -f2`
		if [[ $name == $2 ]]
		then	
			#echo "$name : $temp_id"
			id=$temp_id
		fi
	done < names.txt
	if [[ $id == 0 ]]
	then
		echo "No such student: $2"
		exit 1
	fi
	while read line;do
		course_id=`echo "$line" | cut -d $'\t' -f1`
		course_name=`echo "$line" | cut -d $'\t' -f2`
		grade=`echo "$line" | cut -d $'\t' -f3`
		
		if [[ $course_id == $id ]]
		then
			if [[ "$grade" == '' ]]
			then
				grade="in progress"
			fi

			echo "$course_name $grade"
		fi

	done  < courses.txt


elif [[ $1 == "-g" ]]
then
	id=0
	while read line;do
		name=`echo "$line" | cut -d $'\t' -f1`
		temp_id=`echo "$line" | cut -d $'\t' -f2`
		if [[ $name == $2 ]]
		then	
			#echo "$name : $temp_id"
			id=$temp_id
		fi
	done < names.txt

	if [[ $id == 0 ]]
	then
		echo "No such student: $2"
		exit 1
	fi


	while read line;do
		course_id=`echo "$line" | cut -d $'\t' -f1`
		course_name=`echo "$line" | cut -d $'\t' -f2`
		grade=`echo "$line" | cut -d $'\t' -f3`
		
		if [[ $course_id == $id ]]
		then
			if [[ ! "$grade" == '' ]]
			then
				echo "$course_name $grade"
			fi
		fi

	done  < courses.txt



elif [[ $1 == "-c" ]]
then
	count=0
	while read line;do
		course_name=`echo "$line" | cut -d $'\t' -f2`

		if [[ $course_name == $2 ]]
		then
			count=$(( count + 1 ))
		fi

	done  < courses.txt
	
	echo "$count"

elif [[ $1 == "-list" ]]
then
	count=0
	while read line;do
		course_name=`echo "$line" | cut -d $'\t' -f2`
		grade=`echo "$line" | cut -d $'\t' -f3`
		if [[ $course_name == $2 ]]
		then
			if [[ $grade == $3 ]]
			then
				count=$(( count + 1 ))
			fi
		fi

	done  < courses.txt
	
	echo "$count"

fi

exit 1
