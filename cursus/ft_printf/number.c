#include "ft_printf.h"

int    ft_putudec(unsigned int n)
{
    char result[12];
    int total;
    int i;

    i = 11;
    result[i--] = 0;
    if (n == 0)
        result[i--] = '0';
    while (n)
    {
        result[i--] = (n % 10) + '0';
        n /= 10; 
    }
    return (ft_putstr(result + i + 1));
}

int    ft_putdec(int n)
{
    char result[12];
    int is_signed;
    unsigned int nn;
    int i;

    is_signed = (n < 0);
    nn = (n < 0) * -n + (n >= 0) * n;
    if (is_signed)
        n *= -1;
    i = 11;
    result[i--] = 0;
    if (n == 0)
        result[i--] = '0';
    while (nn)
    {
        result[i--] = (nn % 10) + '0';
        nn /= 10; 
    }
    if (is_signed)
        result[i--] = '-';
    return (ft_putstr(result + i + 1));
}

int    ft_puthex(unsigned int n, char *base)
{
    char result[12];
    int c;
    int i;

    i = 11;
    result[i--] = 0;
    if (n == 0)
        result[i--] = '0';
    while (n)
    {
        c = n % 16;
        if (c < 10)
            result[i--] = c + '0';
        else
            result[i--] = base[c - 10];
        n /= 16; 
    }
    return (ft_putstr(result + i + 1));
}

int	ft_putaddr(unsigned long n, char *base)
{
    char	result[15];
    int		c;
    int		i;

    i = 11;
    if (n == 0)
        return (ft_putstr("(nil)"));
    result[i--] = 0;
    if (n == 0)
        result[i--] = '0';
    while (n)
    {
        c = n % 16;
        if (c < 10)
            result[i--] = c + '0';
        else
            result[i--] = base[c - 10];
        n /= 16; 
    }
    result[i--] = 'x';
    result[i--] = '0';
    return (ft_putstr(result + i + 1));
}

