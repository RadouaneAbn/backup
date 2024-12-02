#include "ft_printf.h"

void	test_chars(void)
{
	int n, m;
	printf("##################################\n");
	printf("testing ft_printf on characters:\n");
	n = printf("printf   : |%c|\n", 'c');
	m = ft_printf("ft_printf: |%c|\n", 'c');
	compaire(n, m);
	n = printf("printf   : |%c|\n", 0);
	m = ft_printf("ft_printf: |%c|\n", 0);
	compaire(n, m);
	n = printf("printf   : |%5c|\n", 65);
	m = ft_printf("ft_printf: |%5c|\n", 65);
	compaire(n, m);
	n = printf("printf   : |%-5c|\n", 'c');
	m = ft_printf("ft_printf: |%-5c|\n", 'c');
	compaire(n, m);
	n = printf("printf   : |%5c|\n", 'c');
	m = ft_printf("ft_printf: |%5c|\n", 'c');
	compaire(n, m);
}

void	test_strings(void)
{
	char	*null;
	char	*str;

	int n, m;
	null = NULL;
	str = "Hello, World!";
	printf("##################################\n");
	printf("testing ft_printf on strings:\n");
	n = printf("printf   : |%s|\n", null);
	m = ft_printf("ft_printf: |%s|\n", null);
	compaire(n, m);
	n = printf("printf   : |%.s|\n", null);
	m = ft_printf("ft_printf: |%.s|\n", null);
	compaire(n, m);
	n = printf("printf   : |%20s|\n", str);
	m = ft_printf("ft_printf: |%20s|\n", str);
	compaire(n, m);
	n = printf("printf   : |%.20s|\n", str);
	m = ft_printf("ft_printf: |%.20s|\n", str);
	compaire(n, m);
	n = printf("printf   : |%20s|\n", str);
	m = ft_printf("ft_printf: |%20s|\n", str);
	compaire(n, m);
	n = printf("printf   : |%.3s|\n", str);
	m = ft_printf("ft_printf: |%.3s|\n", str);
	compaire(n, m);
	n = printf("printf   : |%-20s|\n", str);
	m = ft_printf("ft_printf: |%-20s|\n", str);
	compaire(n, m);
}

void	test_int(void)
{
	int n, m;
	printf("##################################\n");
	printf("\ntesting ft_printf on integers:\n");
	n = printf("printf   : |%020d|\n", INT_MAX);
	m = ft_printf("ft_printf: |%020d|\n", INT_MAX);
	compaire(n, m);
	n = printf("printf   : |%20d|\n", INT_MAX);
	m = ft_printf("ft_printf: |%20d|\n", INT_MAX);
	compaire(n, m);
	n = printf("printf   : |%-20d|\n", INT_MAX);
	m = ft_printf("ft_printf: |%-20d|\n", INT_MAX);
	compaire(n, m);
	n = printf("printf   : |%d|\n", INT_MIN);
	m = ft_printf("ft_printf: |%d|\n", INT_MIN);
	compaire(n, m);
	n = printf("printf   : |%d|\n", (int)SIZE_MAX);
	m = ft_printf("ft_printf: |%d|\n", (int)SIZE_MAX);
	compaire(n, m);
	n = printf("printf   : |%+d|\n", 17);
	m = ft_printf("ft_printf: |%+d|\n", 17);
	compaire(n, m);
	n = printf("printf   : |%+d|\n", -17);
	m = ft_printf("ft_printf: |%+d|\n", -17);
	compaire(n, m);
	n = printf("printf   : |% d|\n", 17);
	m = ft_printf("ft_printf: |% d|\n", 17);
	compaire(n, m);
	n = printf("printf   : |% d|\n", -17);
	m = ft_printf("ft_printf: |% d|\n", -17);
	compaire(n, m);
	n = printf("printf   : |% d|\n", 0);
	m = ft_printf("ft_printf: |% d|\n", 0);
	compaire(n, m);
	n = printf("printf   : |%+d|\n", 0);
	m = ft_printf("ft_printf: |%+d|\n", 0);
	compaire(n, m);
	n = printf("printf   : |%+7.5d|\n", 300000);
	m = ft_printf("ft_printf: |%+7.5d|\n", 300000);
	compaire(n, m);
}

void test_uint(void)
{
	int n, m;
	printf("##################################\n");
	printf("\ntesting ft_printf on unsigned integers:\n");
	n = printf("printf   : |%u|\n", -1);
	m = ft_printf("ft_printf: |%u|\n", -1);
	compaire(n, m);
	n = printf("printf   : |%u|\n", 0);
	m = ft_printf("ft_printf: |%u|\n", 0);
	compaire(n, m);
	n = printf("printf   : |%u|\n", (unsigned int)SIZE_MAX);
	m = ft_printf("ft_printf: |%u|\n", (unsigned int)SIZE_MAX);
	compaire(n, m);
}

void test_hex(void)
{
	int n, m;
	printf("##################################\n");
	printf("\ntesting ft_printf on hex:\n");
	n = printf("printf   : |%x|\n", 255);
	m = ft_printf("ft_printf: |%x|\n", 255);
	compaire(n, m);
	n = printf("printf   : |%X|\n", -1);
	m = ft_printf("ft_printf: |%X|\n", -1);
	compaire(n, m);
	n = printf("printf    [%%#X]: |%#X|\n", 0);
	m = ft_printf("ft_printf [%%#X]: |%#X|\n", 0);
	compaire(n, m);
	n = printf("printf   : |%#x|\n", 255);
	m = ft_printf("ft_printf: |%#x|\n", 255);
	compaire(n, m);
	n = printf("printf   : |%#X|\n", -1);
	m = ft_printf("ft_printf: |%#X|\n", -1);
	compaire(n, m);
	n = printf("printf   : |%#X|\n", 0);
	m = ft_printf("ft_printf: |%#X|\n", 0);
	compaire(n, m);
}

void test_addr(void)
{
	int n, m;
	char *s = "red";
	char *null = NULL;
	printf("\ntesting ft_printf on addr:\n");
	n = printf("printf   : |%p|\n", &s);
	m = ft_printf("ft_printf: |%p|\n", &s);
	compaire(n, m);
	n = printf("printf   : |%p|\n", &null);
	m = ft_printf("ft_printf: |%p|\n", &null);
	compaire(n, m);
	n = printf("printf   : |%p|\n", 0);
	m = ft_printf("ft_printf: |%p|\n", 0);
	compaire(n, m);
}

int	main(void)
{
	static char	*snull = NULL;
	char		*null;
	char		*s;

	int n, m;
	test_chars();
	test_strings();
	test_int();
	test_uint();
	test_hex();
	test_addr();
	
	return (0);
	// n = printf("printf   : |%p|%p|\n", LONG_MIN, LONG_MAX);
	// m = ft_printf("ft_printf: |%p|%p|\n", LONG_MIN, LONG_MAX);
	// compaire(n, m);
	// n = printf("printf   : |%p|%p|\n", -ULONG_MAX, ULONG_MAX);
	// m = ft_printf("ft_printf: |%p|%p|\n", -ULONG_MAX, ULONG_MAX);
	// compaire(n, m);
}
