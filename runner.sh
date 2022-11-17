#!/bin/bash

for (( i = 0; i < 500; i++))
do
	echo "Run no." $i  `./$1`
	
done
