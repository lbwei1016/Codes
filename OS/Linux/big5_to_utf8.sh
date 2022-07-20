#!/bin/bash
#Program
#Convert Big-5(actually is ISO-8859 here) files to UTF-8
#Currently, you must press Ctrl^C to end this program.
#History: (date/author/version)
#2021/08/03     LBWei   1.0
#2022/07/20     lbwei   2.0     Now `ls -R | ./big5_to_utf8.sh` works.
path='./'
echo "Please enter the pathes to the files going to be converted from big5 to UTF-8."
while read file
do
    echo ${file} | grep -q "/"
    if [ $? == 0 ];
    then
        file=`echo ${file} | cut -d : -f 1`
        path=${file}/
        #continue
    # else  
    #  echo "Oops"
    fi

    echo ${path}${file}
    file -b ${path}${file} > id.dat
    grep -q ISO-8859 id.dat 
    # if current file is ISO-8859
    if [ $? == 0 ]; 
    then
        grep -q UTF-8 id.dat
        # if current file is not UTF-8
        # actually this statement is verbose
        if [ $? == 1 ];
        then
            iconv -f BIG-5 -t utf8 -o ${path}${file} ${path}${file}
        else 
            echo "Already UTF-8"
        fi
    else 
        echo "Not Big-5"
    fi
    rm id.dat
done
exit 0