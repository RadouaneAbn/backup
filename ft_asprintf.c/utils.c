#include "ft_asprintf.h"

static void	calculate_width_precision(char *s, t_opt *opt, int *slen, int *sign)
{
	if (opt->precision[0] && opt->precision[1] == 0 && s[0] == '0')
		*slen = 0;
	if (char_in_chaset(*s, "-+ "))
	{
		*sign = 1;
		(*slen)--;
	}
	if (opt->precision[1] >= *slen)
		opt->width -= opt->precision[1] + *sign;
	else
		opt->width -= *slen + *sign;
	if (opt->width < 0)
		opt->width = 0;
}

int	copy_number(t_buffer *buffer, char *s, t_opt *opt)
{
	int		slen;
	char	*new_s;
	int		sign;

	if (s == NULL)
		new_s = "(null)";
	else
		new_s = s;
	slen = ft_strlen(new_s);
	sign = 0;
	calculate_width_precision(new_s, opt, &slen, &sign);
	return (copy_to_buffer_2(buffer, opt, (t_str_len){new_s, }, sign));
}

char	*convert(char *result, int sign_space, unsigned long n, char *base)
{
	int	k;
	int	blen;

	blen = ft_strlen(base);
	k = 31;
	result[k--] = 0;
	if (n == 0)
		result[k--] = '0';
	while (n)
	{
		result[k--] = base[n % blen];
		n /= blen;
	}
	if (sign_space)
		result[k--] = sign_space;
	return (result + k + 1);
}
