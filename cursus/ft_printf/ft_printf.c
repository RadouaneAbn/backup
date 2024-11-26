#include "ft_printf.h"


void append_char(t_buf *buf, int c)
{
    buf->s[buf->i++] = c;
}

void append_string(t_buf *buf, char *s)
{
    int i;

    i = buf->i;
    if (s == NULL)
        buf->i += ft_strlcpy((buf->s) + buf->i, "(null)", 7);
    else
        buf->i += ft_strlcpy((buf->s) + buf->i, s, 1048576 - buf->i);
}

int append_to_buffer(t_buf *buf, va_list args, const char *s, int i)
{
    if (s[i] == '%')
        append_char(buf, '%');
    else if (s[i] == 'c')
        append_char(buf, va_arg(args, int));
    else if (s[i] == 's')
        append_string(buf, va_arg(args, char *));
    else if (s[i] == 'i' || s[i] == 'd')
        append_dec(buf, va_arg(args, int));
    else if (s[i] == 'u')
        append_udec(buf, va_arg(args, unsigned int));
    else if (s[i] == 'x')
        append_hex(buf, va_arg(args, unsigned int), "abcdef");
    else if (s[i] == 'X')
        append_hex(buf, va_arg(args, unsigned int), "ABCDEF");
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
    buf.s[0] = 0;
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
