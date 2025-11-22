#include "ft_asprintf.h"



int	copy_addr_helper(t_buffer *buffer, char *s, t_opt *opt)
{
	int		slen;
	int		count;
	char	*new_s;

	if (s == NULL)
		new_s = "(null)";
	else
		new_s = s;
	slen = ft_strlen(new_s);
	return (copy_to_buffer(buffer, opt, new_s, slen));
}

int	copy_addr(t_buffer *buffer, va_list args, t_opt *opt)
{
	char			result[32];
	unsigned long	n;
	char			*s;

	n = va_arg(args, unsigned long);
	opt->fill = ' ';
	if (n == 0)
		return (copy_addr_helper(buffer, "(nil)", opt));
	s = convert(result, 0, n, "0123456789abcdef");
	*(--s) = 'x';
	*(--s) = '0';
	return (copy_addr_helper(buffer, s, opt));
}