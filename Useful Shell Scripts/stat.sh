#!/bin/bash
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

entered=`echo "$text" | awk -F"," '$4 == "Enter"'`

cmd="$1"
if [ ${#1} -lt 15 ]
then
    sorted_list=`echo "$entered" | awk -v x=$cmd -F":" '$1~x'`
elif [[ ${#1} -lt 27 && ${#1} -gt 14 ]]
then
    sorted_list=`echo "$entered" | awk -v x=$cmd -F"," '$1~x'`
fi

if [ ${#sorted_list} -lt 1 ]
then
    echo "No records found"
    exit 1
fi

stations=`echo "$sorted_list" | cut -d "," -f 3 | sort | uniq`

station_list=()
for i in $stations
do
    station_list+=("$i")
done



#counting the distinct number of each station
count=()
for station in $stations
do
    distinct=`echo "$sorted_list" | cut -d ',' -f 2,3 | awk -v x=$station -F"," '$2 == x' | sort | uniq | wc -l`
    count+=("$distinct")
done


c=${count[0]}
for station_count in ${count[@]}
do
    if [ $station_count -gt $c ]
    then
        c="$station_count"
    fi
done 


final=()
i=0
for station_count in ${count[@]}
do
    if [ $station_count -eq $c ]
    then
        final+=(${station_list["$i"]})
    fi
    i=$((i+1))
done 


st=""
for station_count in ${final[@]}
do
    st=`echo -e "$st\n$station_count"`
done 


sorted_stations="`echo "$st" | sort -r`"


for sorted_station in $sorted_stations
do
    echo "$c $sorted_station"
done 



