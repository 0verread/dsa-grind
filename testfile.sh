#!/bin/bash 

while getopts f: flag
    do 
		case "${flag}" in
		    f) filename=${OPTARG};;
		esac
    done

OUT_FILE=$(echo $filename | cut -d '.' -f 1)

echo [`date`] ": running: $filename"
g++ $filename -o out/$OUT_FILE; 
echo [`date`] ": output:"
echo
./out/$OUT_FILE
echo
