#include "ft_printf.h"

int ft_putchar(int c)
{
    return (write(1, &c, 1));
}

int ft_strlen(char *s)
{
	int i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int ft_putstr(char *s)
{
	if (s == NULL)
		return (write(1, "(null)", 6));
	return (write(1, s, ft_strlen(s)));
}

int find_flag(va_list args, const char *s, int i)
{
    if (s[i] == '%')
        return (ft_putchar('%'));
    else if (s[i] == 'c')
        return (ft_putchar(va_arg(args, int)));
    else if (s[i] == 's')
        return (ft_putstr(va_arg(args, char *)));
    else if (s[i] == 'i' || s[i] == 'd')
        return (ft_putdec(va_arg(args, int)));
    else if (s[i] == 'u')
        return (ft_putudec(va_arg(args, unsigned int)));
    else if (s[i] == 'x')
        return (ft_puthex(va_arg(args, unsigned int), "abcdef"));
    else if (s[i] == 'X')
        return (ft_puthex(va_arg(args, unsigned int), "ABCDEF"));
    else if (s[i] == 'p')
        return (ft_putaddr(va_arg(args, unsigned long), "abcdef"));
    return (2);
}

int ft_printf(const char *str, ...)
{
    int i;
    int count;
    va_list args;
    va_start(args, str);

    if (str == NULL)
        return (0);
    i = 0;
    count = 0;
    while (str[i])
    {
        if (str[i] == '%' && str[i + 1])
            count += find_flag(args, str, ++i);
        else
            count += ft_putchar(str[i]);
	i++;
    }
    return (count);
}
