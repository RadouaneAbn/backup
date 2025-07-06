#include "ft_asprintf.h"

int	copy_udec(t_buffer *buffer, va_list args, t_opt *opt)
{
	char			result[32];
	unsigned int	n;
	char			*s;

	n = va_arg(args, unsigned int);
	s = convert(result, opt->leading_space_sign, n, "0123456789");
	if (opt->precision[0] && opt->fill == '0')
		opt->fill = ' ';
	return (copy_number(buffer, s, opt));
}
