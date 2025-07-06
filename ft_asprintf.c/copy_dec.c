#include "ft_asprintf.h"

int	copy_dec(t_buffer *buffer, va_list args, t_opt *opt)
{
	char	result[32];
	int		n;
	char	*s;
	char	leading_space;

	n = va_arg(args, int);
	if (n < 0)
		leading_space = '-';
	else
		leading_space = opt->leading_space_sign;
	if (n < 0)
		s = convert(result, leading_space, -(unsigned long)(n), "0123456789");
	else
		s = convert(result, leading_space, n, "0123456789");
	if (opt->precision[0] && opt->fill == '0')
		opt->fill = ' ';
	return (copy_number(buffer, s, opt));
}