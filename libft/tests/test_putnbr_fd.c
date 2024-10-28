#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);

int main() {

    ft_putnbr_fd(11, 1);
    ft_putchar_fd('\n', 1);
    ft_putnbr_fd(-11, 1);
    ft_putchar_fd('\n', 1);
    ft_putnbr_fd(0, 1);
    ft_putchar_fd('\n', 1);
    ft_putnbr_fd(INT_MAX, 1);
    ft_putchar_fd('\n', 1);
    ft_putnbr_fd(INT_MIN, 1);
    ft_putchar_fd('\n', 1);
    ft_putnbr_fd(11, 2);
    ft_putchar_fd('\n', 2);
    ft_putnbr_fd(-11, 2);
    ft_putchar_fd('\n', 2);
    ft_putnbr_fd(0, 2);
    ft_putchar_fd('\n', 2);
    ft_putnbr_fd(INT_MAX, 2);
    ft_putchar_fd('\n', 2);
    ft_putnbr_fd(INT_MIN, 2);
    ft_putchar_fd('\n', 2);
    int fd = open("test.txt", O_CREAT | O_RDWR, 0644);
    if (fd == -1) {
        printf("Failed to open file");
        return 1;
    }
    ft_putnbr_fd(11, fd);
    ft_putchar_fd('\n', fd);
    ft_putnbr_fd(-11, fd);
    ft_putchar_fd('\n', fd);
    ft_putnbr_fd(0, fd);
    ft_putchar_fd('\n', fd);
    ft_putnbr_fd(INT_MAX, fd);
    ft_putchar_fd('\n', fd);
    ft_putnbr_fd(INT_MIN, fd);
    ft_putchar_fd('\n', fd);
    close(fd);
    return (0);
}