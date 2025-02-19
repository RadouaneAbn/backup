#!/bin/bash

num=1
while [ $num -le 500 ]; do
	args=$(shuf -i 1-10000 -n $num | tr '\n' ' ')
  valgrind ./push_swap "$args" | ./checker "$args"
	# output=$(./push_swap "$args" | ./checker "$args")
	num=$((num + 1))
done

