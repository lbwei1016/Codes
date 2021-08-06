#!/bin/bash
#Program
#   Convert Big-5(actually is ISO-8859 here) files to UTF-8
#History: (date/author/version)
#2021/08/03     LBWei   1.0
while read file
do
    echo ${file}
    file -b ${file} > id.dat
    grep -q ISO-8859 id.dat 
    # if current file is ISO-8859
    if [ $? == 0 ]; 
    then
        grep -q UTF-8 id.dat
        # if current file is not UTF-8
        # actually this statement is verbose
        if [ $? == 1 ];
        then
            iconv -f BIG-5 -t utf8 -o ${file} ${file}
        else 
            echo "Already UTF-8"
        fi
    else 
        echo "Not Big-5"
    fi
    rm id.dat
done
exit 0