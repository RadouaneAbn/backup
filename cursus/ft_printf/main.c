#include "ft_printf.h"

int	main(void)
{
	static char	*snull = NULL;
	char		*null;
	char		*s;

	int n, m;
	null = NULL;

    char *ss = NULL;

    n = printf("printf   : |%s|\n", ss);
    m = ft_printf("ft_printf: |%s|\n", ss);
    printf("%d: bytes printed\n", n);
    printf("%d: bytes printed\n\n", m);

	printf("testing ft_printf on strings:\n");
	n = printf("printf   : |%s|\n", "test string");
	m = ft_printf("ft_printf: |%s|\n", "test string");
	printf("%d: bytes printed\n", n);
	printf("%d: bytes printed\n\n", m);
	n = printf("printf   : |%s|\n", null);
	m = ft_printf("ft_printf: |%s|\n", null);
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

	n = printf("printf   : |%+d|\n", 17);
	m = ft_printf("ft_printf: |%+d|\n", 17);
	printf("%d: bytes printed\n", n);
	printf("%d: bytes printed\n\n", m);
	n = printf("printf   : |%+d|\n", -17);
	m = ft_printf("ft_printf: |%+d|\n", -17);
	printf("%d: bytes printed\n", n);
	printf("%d: bytes printed\n\n", m);

	n = printf("printf   : |% d|\n", 17);
	m = ft_printf("ft_printf: |% d|\n", 17);
	printf("%d: bytes printed\n", n);
	printf("%d: bytes printed\n\n", m);
	n = printf("printf   : |% d|\n", -17);
	m = ft_printf("ft_printf: |% d|\n", -17);
	printf("%d: bytes printed\n", n);
	printf("%d: bytes printed\n\n", m);

	n = printf("printf   : |% d|\n", 0);
	m = ft_printf("ft_printf: |% d|\n", 0);
	printf("%d: bytes printed\n", n);
	printf("%d: bytes printed\n\n", m);
	n = printf("printf   : |%+d|\n", 0);
	m = ft_printf("ft_printf: |%+d|\n", 0);
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

	printf("##################################\n");
	printf("\ntesting ft_printf on hex:\n");
	n = printf("printf   : |%x|\n", 255);
	m = ft_printf("ft_printf: |%x|\n", 255);
	printf("%d: bytes printed\n", n);
	printf("%d: bytes printed\n\n", m);
	n = printf("printf   : |%X|\n", -1);
	m = ft_printf("ft_printf: |%X|\n", -1);
	printf("%d: bytes printed\n", n);
	printf("%d: bytes printed\n\n", m);
	n = printf("printf    [%%#X]: |%#X|\n", 0);
	m = ft_printf("ft_printf [%%#X]: |%#X|\n", 0);
	printf("%d: bytes printed\n", n);
	printf("%d: bytes printed\n\n", m);

	n = printf("printf   : |%#x|\n", 255);
	m = ft_printf("ft_printf: |%#x|\n", 255);
	printf("%d: bytes printed\n", n);
	printf("%d: bytes printed\n\n", m);
	n = printf("printf   : |%#X|\n", -1);
	m = ft_printf("ft_printf: |%#X|\n", -1);
	printf("%d: bytes printed\n", n);
	printf("%d: bytes printed\n\n", m);
	n = printf("printf   : |%#X|\n", 0);
	m = ft_printf("ft_printf: |%#X|\n", 0);
	printf("%d: bytes printed\n", n);
	printf("%d: bytes printed\n\n", m);

	s = "red";
	printf("\ntesting ft_printf on addr:\n");
	n = printf("printf   : |%p|\n", &s);
	m = ft_printf("ft_printf: |%p|\n", &s);
	printf("%d: bytes printed\n", n);
	printf("%d: bytes printed\n\n", m);
	n = printf("printf   : |%p|\n", &null);
	m = ft_printf("ft_printf: |%p|\n", &null);
	printf("%d: bytes printed\n", n);
	printf("%d: bytes printed\n\n", m);
	n = printf("printf   : |%p|\n", &snull);
	m = ft_printf("ft_printf: |%p|\n", &snull);
	printf("%d: bytes printed\n", n);
	printf("%d: bytes printed\n\n", m);
	n = printf("printf   : |%p|%p|\n", LONG_MIN, LONG_MAX);
	m = ft_printf("ft_printf: |%p|%p|\n", LONG_MIN, LONG_MAX);
	printf("%d: bytes printed\n", n);
	printf("%d: bytes printed\n\n", m);
	n = printf("printf   : |%p|%p|\n", -ULONG_MAX, ULONG_MAX);
	m = ft_printf("ft_printf: |%p|%p|\n", -ULONG_MAX, ULONG_MAX);
	printf("%d: bytes printed\n", n);
	printf("%d: bytes printed\n\n", m);
}
