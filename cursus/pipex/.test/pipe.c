#include "header.h"

int main () {
	int fd[2];
	int size;
	char buf[20];

	pipe(fd);

	int id = fork();

	if (id == 0)
	{
		close(fd[0]);
		write(fd[1], "hello", 5);
		close(fd[1]);
	} else {
		close(fd[1]);
		size = read(fd[0], buf, 20);
		buf[size] = 0;
		close(fd[0]);
		printf(buf);
	}

	return (0);
	
}
