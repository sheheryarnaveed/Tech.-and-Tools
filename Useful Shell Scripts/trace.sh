#!/bin/bash

if [ $# -lt 1 ]
then
    echo "Usage: ./trace.sh (patientID)"
    exit 1
fi

log_files=`ls *.log`
text=""
IFS=$'\n'
for file in $log_files
do
    for line in `cat $file`
    do
        text=`echo -e "$text\n$line"`
    done
done

ac=`echo "$text" | awk -v x=$1 -F"," '$3 == x'`
ac=`echo "$ac" | sort -t\: -nr -k1,2V -k2 -k3`

if [ "${#ac}" -eq 0 ]
then
    echo "No records found for $1"
    exit 1
fi

for i in $ac
do
    echo "$i" >> "$1".log
done