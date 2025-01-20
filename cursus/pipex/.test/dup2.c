#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main () {
    int fd = open("test_file_2.txt", O_WRONLY | O_APPEND | O_CREAT);
    if (fd < 0) {
        printf("Error\n");
        return (1);
    }

    int new_fd = dup2(fd, 1);

    write(fd, "hello world\n", 12);
    write(new_fd, "hello world again\n", 18);
    // 
    write(1, "hello world again\n", 18);

    close(fd);
    close(new_fd);
    return (0);
}
