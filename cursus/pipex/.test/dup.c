#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main () {
    int fd = open("test_file.txt", O_WRONLY | O_APPEND);
    if (fd < 0) {
        printf("Error\n");
        return (1);
    }

    int new_fd = dup(fd);

    write(fd, "hello world", 11);
    write(new_fd, "hello world again", 17);

    close(fd);
    close(new_fd);
    return (0);
}