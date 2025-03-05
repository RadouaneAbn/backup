#include <stdio.h>

void	*ft_memset(void *b, int c, size_t len);

int main() {
    int n = 42;
    void *c = &n;

    printf("%p\n", &n);
    printf("%p\n", c);
    printf("before memset: %d\n", n);
    ft_memset((unsigned char *)c, 57, 1);
    ft_memset((unsigned char *)c + 1, 5, 1);

    printf("after memset : %d\n", n);
    return (0);
}