Example of the command to be like:
	```
	echo "hello" > in
	echo "world" >> in
	```

now we have hello world separated with a new line

The command:
	$> < in cat | wc -l > out
	$> cat out

out now contains the output of wc -l which is 2 for the above example.

Format:
	$> < file_to_read cmd1 | cmd2 > file_to_write

Problems 1:
	`command get checked even if its without a path
	example grepp gets treated like a valid command even tho its not in path`
	Input:
		./pipex in cat grepp out
	Output:
		pipex: grepp: Permission denied
	Expected:
		pipex: grepp: Command not found

