#!/bin/bash
#!/bin/bash
log_files=`ls *.log`

for file in $log_files
do
    text=""
    IFS=$'\n'
    for line in `cat $file`
    do
        text=`echo -e "$text\n$line"`
    done
    
    medicines=`echo "$text" | cut -d "," -f 4 | sort | uniq`
    
    medicine_list=()
    for i in $medicines
    do
        medicine_list+=("$i")
    done
    
    
    count=()
    for medicine in $medicines
    do
        distinct=`echo "$text" | cut -d ',' -f 4 | awk -v x=$medicine -F"," '$1 == x' | sort | wc -l`
        count+=("$distinct")
    done
    
   
    
    y=0
    for med in $medicines
    do
        echo "${medicine_list[y]},${count[y]}" >> file.txt
        y=$((y+1))
    done
    
    ac=`sort -t\, -k 2nr -k 1r file.txt`
    list=""
    y=0
    
    echo "$file:"
    for i in $ac
    do
        f=`echo "$i" | cut -d ',' -f 2`
        s=`echo "$i" | cut -d ',' -f 1`
        echo "$f $s"
        if [ "$y" -eq 2 ]
        then
            break
        fi
        y=$((y+1))
    done
    
    rm -rf file.txt
    
    
    
    
done
