#include "get_next_line.h"

int main() {
    int fd = open("text.txt", O_RDONLY);
    int i = 0;

    char *s = get_next_line(fd);
    printf("[%s]\n", s);
    return (0);
}