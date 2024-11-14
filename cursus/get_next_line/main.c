#include "get_next_line.h"

int main() {
    int fd = open("text.txt", O_RDONLY);
    int i = 0;
    char *s;

    while ((s = get_next_line(fd)) != NULL)
    {
        printf("%s", s);
        free(s);
    }
    return (0);
}