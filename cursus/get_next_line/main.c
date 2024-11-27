#include "get_next_line.c"

int main() {
	int fd = 0;
	int i = 1;
	char *s;

	while ((s = get_next_line(fd)))
		printf("%d: %s", i++, s);
}
