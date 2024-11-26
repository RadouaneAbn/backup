#include "ft_printf.h"


int main() {
    int n, m;
    printf("testing ft_printf on strings:\n");
    n = printf("printf   : |%s|\n", "test string");
    m = ft_printf("ft_printf: |%s|\n", "test string");
    printf("%d: bytes printed\n", n);
    printf("%d: bytes printed\n\n", m);

    n = printf("printf   : |%s|\n", NULL);
    m = ft_printf("ft_printf: |%s|\n", NULL);
    printf("%d: bytes printed\n", n);
    printf("%d: bytes printed\n\n", m);

    printf("##################################\n");

    printf("testing ft_printf on characters:\n");
    n = printf("printf   : |%c|\n", 'c');
    m = ft_printf("ft_printf: |%c|\n", 'c');
    printf("%d: bytes printed\n", n);
    printf("%d: bytes printed\n\n", m);

    n = printf("printf   : |%c|\n", 0);
    m = ft_printf("ft_printf: |%c|\n", 0);
    printf("%d: bytes printed\n", n);
    printf("%d: bytes printed\n\n", m);

    n = printf("printf   : |%c|\n", 65);
    m = ft_printf("ft_printf: |%c|\n", 65);
    printf("%d: bytes printed\n", n);
    printf("%d: bytes printed\n\n", m);

    printf("##################################\n");

    printf("\ntesting ft_printf on integers:\n");
    n = printf("printf   : |%d|\n", INT_MAX);
    m = ft_printf("ft_printf: |%d|\n", INT_MAX);
    printf("%d: bytes printed\n", n);
    printf("%d: bytes printed\n\n", m);

    n = printf("printf   : |%d|\n", INT_MIN);
    m = ft_printf("ft_printf: |%d|\n", INT_MIN);
    printf("%d: bytes printed\n", n);
    printf("%d: bytes printed\n\n", m);

    n = printf("printf   : |%d|\n", (int)SIZE_MAX);
    m = ft_printf("ft_printf: |%d|\n", (int)SIZE_MAX);
    printf("%d: bytes printed\n", n);
    printf("%d: bytes printed\n\n", m);

    printf("##################################\n");

    printf("\ntesting ft_printf on unsigned integers:\n");
    n = printf("printf   : |%u|\n", -1);
    m = ft_printf("ft_printf: |%u|\n", -1);
    printf("%d: bytes printed\n", n);
    printf("%d: bytes printed\n\n", m);

    n = printf("printf   : |%u|\n", 0);
    m = ft_printf("ft_printf: |%u|\n", 0);
    printf("%d: bytes printed\n", n);
    printf("%d: bytes printed\n\n", m);

    n = printf("printf   : |%u|\n", (unsigned int)SIZE_MAX);
    m = ft_printf("ft_printf: |%u|\n", (unsigned int)SIZE_MAX);
    printf("%d: bytes printed\n", n);
    printf("%d: bytes printed\n\n", m);
}
