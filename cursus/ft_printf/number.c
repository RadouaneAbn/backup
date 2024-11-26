#include "ft_printf.h"

void appendto_buffer(t_buf *buf, char *s)
{
    int slen;

    slen = ft_strlen(s);
    if (slen < BUFFER_SIZE - buf->i)
        copyto_buffer(buf, s);
    else
    {
        write(1, buf->s, buf->i);
        buf->i = 0;
        appendto_buffer(buf, s);
    }
    return ;
}

void    append_udec(t_buf *buf, unsigned int n)
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
    appendto_buffer(buf, result + i + 1);
}

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
    if (is_signed)
        buf->s[buf->i++] = '-';
    appendto_buffer(buf, result + i + 1);
}

void    append_hex(t_buf *buf, unsigned int n, char *base)
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
    appendto_buffer(buf, result + i + 1);
}

void    append_addr(t_buf *buf, unsigned long n, char *base)
{
    char result[15];
    int c;
    int i;

    i = 11;
    result[i--] = 0;
    if (n == 0)
        result[i--] = '0';
    while (i >= 2)
    {
        c = n % 16;
        if (c < 10)
            result[i--] = c + '0';
        else
            result[i--] = base[c - 10];
        n /= 16; 
    }
    // result[i--] = 'x';
    // result[i--] = '0';
    appendto_buffer(buf, result + i + 1);
}

void	copyto_buffer(t_buf *buf, const char *src)
{
	int	i;
	int	src_len;

	i = 0;
	while (src[i])
		buf->s[buf->i++] = src[i++];
}