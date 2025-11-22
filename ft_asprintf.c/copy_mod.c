#include "ft_asprintf.h"

int	copy_mod(t_buffer *buffer, va_list args, t_opt *opt)
{
	(void)opt;
	(void)args;
	return (append_char_to_buffer(buffer, '%'));
}

