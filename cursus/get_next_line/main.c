#include "get_next_line.h"

int main() {
    // int fd = open("text.txt", O_RDONLY);
    int fd = open("text.txt", O_RDONLY);
    int i = 0;
    char *s;

    printf("BUFFER SIZE: %d\n\n", BUFFER_SIZE);
    while ((s = get_next_line(fd)) != NULL )
    {
        printf("%s", s);
        free(s);
        i++;
    }
    return (0);
}
