#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
void	ft_putendl_fd(char *s, int fd);
int main() {

    ft_putendl_fd("hola", 1);
    ft_putendl_fd("132", 1);
    ft_putendl_fd("hola", 2);
    ft_putendl_fd("", 2);
    int fd = open("test.txt", O_CREAT | O_RDWR, 0644);
    if (fd == -1) {
        printf("Failed to open file");
        return 1;
    }
    ft_putendl_fd("hola", fd);
    ft_putendl_fd("", fd);
    close(fd);
    return (0);
}