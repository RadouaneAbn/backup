#!/bin/bash

num=1
total_wrong=0
while [ $num -le 500 ]; do
	echo "testing $num numbers"
	count=0
	while [ $count -lt 3 ]; do
		args=$(shuf -i 1-10000 -n $num | tr '\n' ' ')

		# Capture Valgrind output
		valgrind_output=$(valgrind --leak-check=full ./push_swap "$args" 2> .tmp9474 | ./checker "$args" 2>> .tmp9474)
		# echo $valgrind_output
		# Extract lines without '==number==' (actual program output)
		program_output=$(echo "$valgrind_output")

		# Check if "All heap blocks were freed" exists (no leaks)
		grep -q "All heap blocks were freed" ".tmp9474"
		leak_exist=$?

		# Print program output if there is any
		if [ -n "$program_output" ]; then
			echo -e "\toutput: $program_output"
		fi

		# Check for leaks
		if [ $leak_exist -eq 0 ]; then
			echo -e "\t\_leak: OK\n"
		else
			echo -e "\t\_leak: KO\n"
			total_wrong=$((total_wrong + 1))
		fi
		count=$((count + 1))
	done

    num=$((num + 1))
done

rm ".tmp9474" 
echo "failed tests: $total_wrong"