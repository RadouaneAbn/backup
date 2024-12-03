#include "../ft_printf.h"

int print_all(int *count, t_opt *opt, char *s, int slen)
{
	if (print_filler(count, opt->fill, opt->pad == 0, opt->width - slen) == -1)
		return (-1);
	if (writer(count, s, slen) == -1)
		return (-1);
	if (print_filler(count, opt->fill, opt->pad == 1, opt->width - slen) == -1)
		return (-1);
	return (*count);
}

int	print_filler(int *count, char c, int cond, int n)
{
	if (cond == 0)
		return (0);
	while (n > 0)
	{
		if (writer(count, &c, 1) == -1)
			return (-1);
		n--;
	}
	return (*count);
}

int	ft_putaddr(char *s, t_opt *opt)
{
	int		slen;
	int		count;
	char	*new_s;

	if (s == NULL)
		new_s = "(null)";
	else
		new_s = s;
	slen = ft_strlen(new_s);
	count = 0;
	if (print_all(&count, opt, new_s, slen) == -1)
		return (-1);
	// if (print_filler(&count, opt->fill, opt->pad == 0, opt->width - slen) == -1)
	// 	return (-1);
	// if (writer(&count, s, slen) == -1)
	// 	return (-1);
	// if (print_filler(&count, opt->fill, opt->pad == 1, opt->width - slen) == -1)
	// 	return (-1);
	return (count);
}

int	ft_putstr(char *s, t_opt *opt)
{
	int		slen;
	int		count;
	char	*new_s;

	if (s == NULL)
	{
		if (opt->precision[0] == 0 || (opt->precision[0] && opt->precision[1] > 5))
			new_s = "(null)";
		else
			new_s = "";
	}
	else
		new_s = s;
	slen = ft_strlen(new_s);
	if (opt->precision[0] && opt->precision[1] < slen)
		slen = opt->precision[1];
	count = 0;
	if (print_all(&count, opt, new_s, slen) == -1)
		return (-1);
	// if (print_filler(&count, opt->fill, opt->pad == 0, opt->width - slen) == -1)
	// 	return (-1);
	// if (writer(&count, new_s, slen) == -1)
	// 	return (-1);
	// if (print_filler(&count, opt->fill, opt->pad == 1, opt->width - slen) == -1)
	// 	return (-1);
	return (count);
}

int	print_precision(int *count, int precision)
{
	while (precision > 0)
	{
		if (writer(count, "0", 1) == -1)
			return (-1);
		precision--;
	}
	return (*count);
}

void calculate_width_precision(char *s, t_opt *opt, int *slen, int *sign)
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

int	ft_putnbr(char *s, t_opt *opt)
{
	int		slen;
	int		count;
	char	*new_s;
	int		sign;

	if (s == NULL)
		new_s = "(null)";
	else
		new_s = s;
	slen = ft_strlen(new_s);
	count = 0;
	sign = 0;
	calculate_width_precision(new_s, opt, &slen, &sign);
	// if (opt->precision[0] && opt->precision[1] == 0 && new_s[0] == '0')
	// 	slen = 0;
	// if (char_in_chaset(*new_s, "-+ "))
	// {
	// 	sign = 1;
	// 	slen--;
	// }
	// if (opt->precision[1] >= slen)
	// 	opt->width -= opt->precision[1] + sign;
	// else
	// 	opt->width -= slen + sign;
	// if (opt->width < 0)
	// 	opt->width = 0;

	if (sign && opt->fill == '0')
		count += ft_putchar(*new_s++);
	if (print_filler(&count, opt->fill, opt->pad == 0, opt->width) == -1 )
		return (-1);
	if (sign && opt->fill == ' ')
		count += ft_putchar(*new_s++);
	if (print_precision(&count, opt->precision[1] - slen) == -1)
		return (-1);
	if (writer(&count, new_s, slen) == -1)
		return (-1);
	if (print_filler(&count, opt->fill, opt->pad == 1, opt->width) == -1 )
		return (-1);
	return (count);
}
