#!/bin/bash 

while getopts f: flag
    do 
	case "${flag}" in
	f) filename=${OPTARG};;
	esac
    done

OUT_FILE=$(echo $filename | cut -d '.' -f 1)
ERR=0;
echo [`date`] ": running: $filename"
g++ $filename -o out/$OUT_FILE || ERR=1;

if [ $ERR -eq 0 ]
    then
	echo [`date`] ": output:"
	echo
	./out/$OUT_FILE
	echo
    else
	echo [`date`] ": could not compile. check for errors"
fi

