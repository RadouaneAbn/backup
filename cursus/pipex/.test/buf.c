#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main() {
	char buf[100];
	int s;

	s = read(0, buf, 100);
	write(1, buf, s);
	return (0);
}
