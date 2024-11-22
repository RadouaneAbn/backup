#include "get_next_line.h"

int main() {
    char *s;
    int fd = open("test", O_RDONLY);
    int i = 1;

    while ((s = get_next_line(fd)) != NULL) {
        printf("%d: %s", i++, s);
        free(s);
    }
    return (0);
}