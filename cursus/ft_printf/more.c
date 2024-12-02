#include "ft_printf.h"

int	ft_strlen(const char *s)
{
	int	count;

	if (s == NULL)
		return (0);
	count = 0;
	while (s[count])
		count++;
	return (count);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	print_filler(char c, int cond, int n)
{
	int	count;

	if (cond == 0)
		return (0);
	count = 0;
	while (n > 0)
	{
		count += write(1, &c, 1);
		n--;
	}
	return (count);
}

int	ft_putstr(char *s, t_opt *opt, char filler)
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
	count += print_filler(filler, opt->pad == 0, opt->width - slen);
	count += write(1, new_s, slen);
	count += print_filler(filler, opt->pad == 1, opt->width - slen);
	return (count);
}

int	ft_putstr_str(char *s, t_opt *opt, char filler)
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
	count += print_filler(filler, opt->pad == 0, opt->width - slen);
	count += write(1, new_s, slen);
	count += print_filler(filler, opt->pad == 1, opt->width - slen);
	return (count);
}

int	print_precision(int precision)
{
	int	count;

	count = 0;
	while (precision > 0)
	{
		count += write(1, "0", 1);
		precision--;
	}
	return (count);
}


// int ft_putstr_2(char *s, t_opt *opt, char filler)
// {
//     int     slen;
//     int     count;
//     char    *new_s;
// 	int		sign;

//     if (s == NULL)
//         new_s = "(null)";
//     else
//         new_s = s;

//     slen = ft_strlen(new_s);
//     count = 0;
//     sign = 0;
//     // Print string with necessary precision
// 	if (char_in_chaset(*new_s, "-+ "))
// 	{
// 		sign = 1;
// 		slen--;
// 	}

//     // Adjust width based on precision
//     if (opt->precision[1] >= slen)
//         opt->width -= opt->precision[1];
//     else
//         opt->width -= slen;

//     if (opt->width < 0)
//         opt->width = 0;

//     // Print filler before string if needed
//     count += print_filler(filler, opt->pad == 0, opt->width);

// 	if (sign && opt->fill == '0')
// 		count += ft_putchar(*new_s++);
//     count += print_precision(opt->precision[1] - slen);
//     count += write(1, new_s, slen);

//     // Print filler after string if needed
//     count += print_filler(filler, opt->pad == 1, opt->width);

//     return count;
// }

int	ft_putstr_2(char *s, t_opt *opt, char filler)
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
	if (char_in_chaset(*new_s, "-+ "))
	{
		sign = 1;
		slen--;
	}
	if (opt->precision[1] >= slen)
		opt->width -= opt->precision[1] + sign;
	else
		opt->width -= slen + sign;
	if (opt->width < 0)
		opt->width = 0;
	// if (sign && opt->fill == '0')
	// 	count += ft_putchar(*new_s++);
	count += print_filler(filler, opt->pad == 0, opt->width);
	if (sign && opt->fill == ' ')
		count += ft_putchar(*new_s++);
	count += print_precision(opt->precision[1] - slen);
	count += write(1, new_s, slen);
	count += print_filler(filler, opt->pad == 1, opt->width);
	return (count);
}

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

void	print_options(t_opt options)
{
	printf("\nalt:---------------->[%d]\n", options.alt);
	printf("leading_space_sign:->[%c]\n", options.leading_space_sign);
	printf("pad:---------------->[%d]\n", options.pad);
	printf("precision:---------->[%d]\n", options.precision[1]);
	printf("width:-------------->[%d]\n", options.width);
}

void	compaire(int n, int m)
{
	printf("[%d - %d]\n", n, m);
	if (n != m)
	{
		printf("❌ FAILURE ❌\n");
	}
	else
	{
		printf("✅ SUCCESS ✅\n");
	}
}