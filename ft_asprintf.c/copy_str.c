#include "ft_asprintf.h"

static int	copy_str_helper(t_buffer *buffer, char *s, t_opt *opt)
{
	int		slen;
    int status;
	char	*new_s;

	if (s == NULL)
	{
		if (opt->precision[0] == 0 || (opt->precision[0]
				&& opt->precision[1] > 5))
			new_s = "(null)";
		else
			new_s = "";
	}
	else
		new_s = s;
	slen = ft_strlen(new_s);
	if (opt->precision[0] && opt->precision[1] < slen)
		slen = opt->precision[1];
	status = copy_to_buffer(buffer, opt, new_s, slen);
	return (status);
}

int	copy_str(t_buffer *buffer, va_list args, t_opt *opt)
{
	char	*s;

	s = va_arg(args, char *);
	opt->fill = ' ';
	return (copy_str_helper(buffer, s, opt));
}