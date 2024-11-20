#include "get_next_line.h"

int main() {
    int i = 0;
    int fd = open("files/multiple_line_with_nl", O_RDONLY);
    char *line = get_next_line(fd);
    printf("current line > %s", line);
    return (0);
}