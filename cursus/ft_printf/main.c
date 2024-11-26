#include "ft_printf.h"

int main() {
    int n;
    printf("testing ft_printf on strings:\n");
    n = ft_printf("[test string] | [%s]\n", "test string");
    printf("%d: bytes printed\n\n", n);
    n = ft_printf("[(null)] | [%s]\n", NULL);
    printf("%d: bytes printed\n\n", n);

    printf("testing ft_printf on characters:\n");
    n = ft_printf("[c] | [%c]\n", 'c');
    printf("%d: bytes printed\n\n", n);
    n = ft_printf("[A] | [%c]\n", 65);
    printf("%d: bytes printed\n\n", n);
    n = ft_printf("[] | [%c]\n", 0);
    printf("%d: bytes printed\n\n", n);
    n = printf("[] | [%c]\n", 0);
    printf("%d: bytes printed\n\n", n);

    printf("\ntesting ft_printf on integers:\n");
    n = ft_printf("[2147483647] | [%d]\n", INT_MAX);
    printf("%d: bytes printed\n\n", n);
    n = ft_printf("[-2147483648] | [%d]\n", INT_MIN);
    printf("%d: bytes printed\n\n", n);
    n = ft_printf("[0] | [%d]\n", -0);
    printf("%d: bytes printed\n\n", n);
    n = ft_printf("[1] | [%d]\n", 1);
    printf("%d: bytes printed\n\n", n);
    n = ft_printf("[-1] | [%d]\n", -1);
    printf("%d: bytes printed\n\n", n);
}
