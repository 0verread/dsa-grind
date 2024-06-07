#!/bin/bash

while getopts f: flag; do
	case "${flag}" in
	f) filename=${OPTARG} ;;
	esac
done

OUT_FILE=$(echo $(basename ${filename}) | cut -d '.' -f 1)
OUT_DIR=".out"
ERR=0
echo [$(date)] ": running: $filename"
if [ ! -d "$OUT_DIR" ]; then
	mkdir "$OUT_DIR"
fi

g++ $filename -o .out/$OUT_FILE || ERR=1

if [ $ERR -eq 0 ]; then
	echo [$(date)] ": output:"
	./$OUT_DIR/$OUT_FILE
	echo
else
	echo [$(date)] ": could not compile. check for errors"
fi
