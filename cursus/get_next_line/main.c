#include "get_next_line.c"

int main() {
	int fd = open("test", O_RDONLY);
	int i = 1;
	char *s;

	while ((s = get_next_line(fd)))
		printf("%d: %s", i++, s);
}
