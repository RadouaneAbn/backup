#include "ft_printf.h"
#include <stdint.h>
#include <stdio.h>
#include <limits.h>

void	compaire(int n, int m)
{
	printf("[%d - %d]\n", n, m);
	if (n != m)
	{
		printf("❌ FAILURE ❌\n");
	}
	else
	{
		printf("✅ SUCCESS ✅\n");
	}
}

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
	n = printf("printf   : |%5.3s|\n", str);
	m = ft_printf("ft_printf: |%5.3s|\n", str);
	compaire(n, m);
	n = printf("printf   : |%-20s|\n", str);
	m = ft_printf("ft_printf: |%-20s|\n", str);
	compaire(n, m);
	n = printf("printf   : |%5.3s|\n", null);
	m = ft_printf("ft_printf: |%5.3s|\n", null);
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

void	test_uint(void)
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

void	test_hex(void)
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
	n = printf("printf   : |%#X|\n", 0);
	m = ft_printf("ft_printf: |%#X|\n", 0);
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

void	test_addr(void)
{
	char	*s;
	char	*null;

	int n, m;
	s = "red";
	null = NULL;
	printf("\ntesting ft_printf on addr:\n");
	n = printf("printf   : |%p|\n", &s);
	m = ft_printf("ft_printf: |%p|\n", &s);
	compaire(n, m);
	n = printf("printf   : |%40p|\n", &s);
	m = ft_printf("ft_printf: |%40p|\n", &s);
	compaire(n, m);
	n = printf("printf   : |%p|\n", (void *)0);
	m = ft_printf("ft_printf: |%p|\n", (void *)0);
	compaire(n, m);
}

// void test_crazy()
// {
// 	int n, m;

// 	printf("\ntesting ft_printf on crazy cases:\n");
// 	n = printf("--> %.0");          /*!!!!!!!!!!!!!!!!*/
// 	printf("\n");
// 	m = ft_printf("--> %.0");          /*!!!!!!!!!!!!!!!!*/
// 	printf("\n");
// 	compaire(n, m);
// 	n = printf("--> %");          /*!!!!!!!!!!!!!!!!*/
// 	printf("\n");
// 	m = ft_printf("--> %");          /*!!!!!!!!!!!!!!!!*/
// 	printf("\n");
// 	compaire(n, m);
// 	n = printf("%r\n");       /*!!!!!!!!!!!!!!!!*/
// 	m = ft_printf("%r\n");       /*!!!!!!!!!!!!!!!!*/
// 	compaire(n, m);
// 	n = printf("%043.45\n"); /*!!!!!!!!!!!!!!!!*/
// 	m = ft_printf("%043.45\n"); /*!!!!!!!!!!!!!!!!*/
// 	compaire(n, m);
// 	n = printf("%043.45y\n"); /*!!!!!!!!!!!!!!!!*/
// 	m = ft_printf("%043.45y\n"); /*!!!!!!!!!!!!!!!!*/
// 	compaire(n, m);
// }

int	main(void)
{
	// printf("%+07i\n", -54);
	// ft_printf("%+07i\n", -54);
	// printf("%7i\n", -14);
	// ft_printf("%7i\n", -14);
	// printf("[ %5.2x ]\n", 1);
	// ft_printf("[ %5.2x ]\n", 1);
	// printf("[ %5.2x ]\n", 10);
	// ft_printf("[ %5.2x ]\n", 10);
	// printf("[%08.5i]\n", -34);
	// ft_printf("[%08.5i]\n", -34);
	// 	printf("%07i\n", -54);
	// ft_printf("%07i\n", -54);
	// printf("[%.0i]\n", 0);
	// ft_printf("[%.0i]\n", 0);
	// printf("[%.i]\n", 0);
	// ft_printf("[%.i]\n", 0);
	// printf("[%5.0i]\n", 0);
	// ft_printf("[%5.0i]\n", 0);
	// printf("[%-5.0i]\n", 0);
	// ft_printf("[%-5.0i]\n", 0);
	// printf("[%-5.i]\n", 0);
	// ft_printf("[%-5.i]\n", 0);
	// printf("[%08.5u]\n", 34);
	// ft_printf("[%08.5u]\n", 34);
	// printf("[%08.5u]\n", 0);
	// ft_printf("[%08.5u]\n", 0);
	// printf("[%08.3u]\n", 8375);
	// ft_printf("[%08.3u]\n\n", 8375);
	// printf("[%08.5x]\n", 34);
	// ft_printf("[%08.5x]\n", 34);
	// printf("[%08.5x]\n", 0);
	// ft_printf("[%08.5x]\n", 0);
	// printf("[%08.3x]\n", 8375);
	// ft_printf("[%08.3x]\n\n", 8375);
	// printf("[%08.5X]\n", 34);
	// ft_printf("[%08.5X]\n", 34);
	// printf("[%08.5X]\n", 0);
	// ft_printf("[%08.5X]\n", 0);
	// printf("[%08.3X]\n", 8375);
	// ft_printf("[%08.3X]\n\n", 8375);
	test_strings();
	test_chars();
	test_int();
	test_uint();
	test_hex();
	test_addr();

	// test_crazy();
	return (0);
}
