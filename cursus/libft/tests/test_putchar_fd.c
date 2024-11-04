# include <stdio.h>
void	ft_putchar_fd(char c, int fd);
int main() {
    char s[] = "hello world\n";
    int i = 0;
    while (s[i]) {
        ft_putchar_fd(s[i], 1);
        i++;
    }
    i = 0;
    while (s[i]) {
        ft_putchar_fd(s[i], 2);
        i++;
    }
    return (0);
}