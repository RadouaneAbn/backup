#include "ft_asprintf.h"

int	copy_hex(t_buffer *buffer, va_list args, t_opt *opt)
{
	char			result[32];
	unsigned int	n;
	char			*s;

	n = va_arg(args, unsigned int);
	s = convert(result, 0, n, "0123456789abcdef");
	if (opt->alt && n)
	{
		*(--s) = 'x';
		*(--s) = '0';
	}
	if (opt->precision[0] && opt->fill == '0')
		opt->fill = ' ';
	return (copy_number(buffer, s, opt));
}
