#include "ft_asprintf.h"

int	copy_char(t_buffer *buffer, va_list args, t_opt *opt)
{
	int	c;
	c = va_arg(args, int);
	if (copy_filler(buffer, ' ', opt->pad == 0, opt->width - 1) == FAILURE)
		return (FAILURE);
	if (append_char_to_buffer(buffer, c) == FAILURE)
		return (FAILURE);
	if (copy_filler(buffer, ' ', opt->pad == 1, opt->width - 1) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
