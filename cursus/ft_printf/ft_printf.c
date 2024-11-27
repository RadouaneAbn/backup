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
	int slen;

	if (s == NULL)
		return (write(1, "(null)", 6));
	return (write(1, s, ft_strlen(s)));
}

int append_to_buffer(va_list args, const char *s, int i)
{
    if (s[i] == '%')
        return (ft_putchar('%'));
    else if (s[i] == 'c')
        ft_putchar(va_arg(args, int));
    else if (s[i] == 's')
        ft_putstr(va_arg(args, char *));
    else if (s[i] == 'i' || s[i] == 'd')
        ft_putdec(va_arg(args, int));
    else if (s[i] == 'u')
        ft_putudec(va_arg(args, unsigned int));
    else if (s[i] == 'x')
        ft_puthex(va_arg(args, unsigned int), "abcdef");
    else if (s[i] == 'X')
        ft_puthex(va_arg(args, unsigned int), "ABCDEF");
    else if (s[i] == 'p')
        ft_putaddr(va_arg(args, unsigned long), "abcdef");
    return (2);
}

int ft_printf(const char *str, ...)
{
    t_buf buf;
    int i;
    int flag;
    va_list args;
    va_start(args, str);

    buf.i = 0;
    buf.total_size = 0;
    i = 0;
    while (str[i])
    {
        if (str[i] == '%' && str[i + 1])
            i += append_to_buffer(&buf, args, str, i + 1);
        else
            buf.s[buf.i++] = str[i++];
    }
    buf.s[buf.i] = 0;
    write(1, buf.s, buf.i);
    return (buf.i);
}
