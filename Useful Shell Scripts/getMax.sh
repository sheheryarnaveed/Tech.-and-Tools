#!/bin/bash
if [ $# -lt 2 ]
then
    echo "Not enough arguments"
elif [ $# -gt 2 ]
then
    echo "Please provide two arguments only!"
else
    text=`cat $1`
   	words=`cat $1 | cut -d "," -f $2`
   	for char in $words
	do
		w=$char
	done
   	
   	for word in $words
	do
	    if [ $word -ge $w ]
		then
		    w=$word
		fi
	done
	echo $w
fi