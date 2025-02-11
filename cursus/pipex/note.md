##### The command format in shell:
```
< in cat | wc -l > out
cat out
```
##### The command format in pipex:
```
./pipex in cat 'wc -l' out
cat out
```
##### The main format of the bonus 1:
```
./pipex input_file cmd_1 cmd_2 ... cmd_n output_fie
```

Problems 1:
> command get checked even if its without a path example grepp gets treated like a valid command even tho its not in path

```
Input:
	./pipex in cat grepp out
Output:
	pipex: grepp: Permission denied
Expected:
	pipex: grepp: Command not found
```


794p