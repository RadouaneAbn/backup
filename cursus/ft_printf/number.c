#include "ft_printf.h"


void    append_dec(t_buf *buf, int n)
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
    // while (i-- > 0)
    //     buf->s[buf->i++] = result[i];
    if (is_signed)
        buf->s[buf->i++] = '-';
    buf->i += ft_strlcpy((buf->s) + buf->i, result + i + 1, 12);
}
