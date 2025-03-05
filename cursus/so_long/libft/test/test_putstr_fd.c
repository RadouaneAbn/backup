#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
void	ft_putstr_fd(char *s, int fd);
int main() {

    ft_putstr_fd("hola\n", 1);
    ft_putstr_fd("132\n", 1);
    ft_putstr_fd("hola\n", 2);
    ft_putstr_fd("\n", 2);
    int fd = open("test.txt", O_CREAT | O_RDWR, 0644);
    if (fd == -1) {
        printf("Failed to open file");
        return 1;
    }
    ft_putstr_fd("hola\n", fd);
    ft_putstr_fd("\n", fd);
    close(fd);
    return (0);
}