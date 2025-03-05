#!/bin/bash

let i=0
let max=0
min=700
let i=0
while true
do
arg=$(shuf -i 0-1000000000 -n $2 | tr '\n' ' ')
	moves=$(./$1 $arg | wc -l)
	if [[ $moves -ge $max ]]
	then
		let max=moves
		printf "max=$max $arg\n" >> errors.txt
	fi
	if [[ $moves -lt min ]]
	then
		let min=$moves
	fi
	printf "\r$moves $i min=$min max=$max"
	let i+=1
done
