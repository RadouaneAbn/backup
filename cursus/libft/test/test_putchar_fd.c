# include <stdio.h>
void	ft_putchar_fd(char c, int fd);
int main() {
    char s[] = "hello world\n";
    int i = 0;
    printf("%s", s);
    while (s[i]) {
        ft_putchar_fd(s[i], 1);
        i++;
    }
    return (0);
}