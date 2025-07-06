#include "ft_asprintf.h"

int	copy_filler(t_buffer *buffer, char c, int cond, int n)
{
	if (cond == 0)
		return (SUCCESS);
	while (n > 0)
	{
		if (append_char_to_buffer(buffer, c) == FAILURE)
			return (FAILURE);
		n--;
	}
	return (SUCCESS);
}

int	copy_precision(t_buffer *buffer, int precision)
{
	while (precision > 0)
	{
		if (append_char_to_buffer(buffer, "0") == FAILURE)
			return (FAILURE);
		precision--;
	}
	return (SUCCESS);
}

int	copy_to_buffer(t_buffer *buffer, t_opt *opt, char *s, int slen)
{
	if (copy_filler(buffer, opt->fill, opt->pad == 0, opt->width - slen) == FAILURE)
		return (FAILURE);
	if (append_string_to_buffer(buffer, s) == FAILURE)
		return (FAILURE);
	if (copy_filler(buffer, opt->fill, opt->pad == 1, opt->width - slen) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int	copy_to_buffer_2(t_buffer *buffer, t_opt *opt, t_str_len str, int sign)
{

	if ((sign && opt->fill == '0') && (append_char_to_buffer(buffer, *(str.s)++) == FAILURE))
		return (FAILURE);
	if (copy_filler(buffer, opt->fill, opt->pad == 0, opt->width) == FAILURE)
		return (FAILURE);
	if ((sign && opt->fill == ' ') && (append_char_to_buffer(buffer, *(str.s)++) == FAILURE))
		return (FAILURE);
	if (copy_precision(buffer, opt->precision[1] - (str.slen)) == FAILURE)
		return (FAILURE);
	if (append_string_to_buffer(buffer, (str.s)) == FAILURE)
		return (FAILURE);
	if (copy_filler(buffer, opt->fill, opt->pad == 1, opt->width) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}