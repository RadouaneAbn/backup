/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabounou <rabounou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:54:09 by rabounou          #+#    #+#             */
/*   Updated: 2024/11/28 15:54:13 by rabounou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	print_udec(va_list args, t_opt *opt)
{
	char	result[32];
	unsigned int		n;
	char	*s;

	n = va_arg(args, unsigned int);
	s = convert(result, opt->leading_space_sign, n, "0123456789");
	return (ft_putstr_2(s, opt, opt->fill));
}

int	print_dec(va_list args, t_opt *opt)
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
	return (ft_putstr_2(s, opt, opt->fill));
}

int	print_hex_cap(va_list args, t_opt *opt)
{
	char			result[32];
	unsigned int	n;
	int				count;
	char			*s;

	count = 0;
	n = va_arg(args, unsigned int);
	s = convert(result, 0, n, "0123456789ABCDEF");
	if (opt->alt && n)
	{
		*(--s) = 'X';
		*(--s) = '0';
	}
	count += ft_putstr_2(s, opt, opt->fill);
	return (count);
}

int	print_hex(va_list args, t_opt *opt)
{
	char			result[32];
	unsigned int	n;
	int				count;
	char			*s;

	n = va_arg(args, unsigned int);
	s = convert(result, 0, n, "0123456789abcdef");
	count = 0;
	if (opt->alt && n)
	{
		*(--s) = 'x';
		*(--s) = '0';
	}
	count += ft_putstr_2(s, opt, opt->fill);
	return (count);
}

int	print_addr(va_list args, t_opt *opt)
{
	char			result[32];
	unsigned long	n;
	char			*s;

	n = va_arg(args, unsigned long);
	if (n == 0)
		return (ft_putstr("(nil)", opt, ' '));
	s = convert(result, 0, n, "0123456789abcdef");
	*(--s) = 'x';
	*(--s) = '0';
	return (ft_putstr(s, opt, ' '));
}
int	print_mod(va_list args, t_opt *opt)
{
	(void)opt;
	(void)args;
	return (ft_putchar('%'));
}