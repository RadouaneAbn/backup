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

char	*convert(char *result, int is_signed, unsigned long n, char *base)
{
	int k;
	int blen;

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
	if (is_signed)
		result[k--] = '-';
	return (result + k + 1);
}

int	print_udec(va_list args, t_opt *opt)
{
	char			result[32];
	unsigned int	n;
	int 			count;
	char			*s;

	n = va_arg(args, unsigned int);
	s = convert(result, 0, n, "0123456789");
	return (ft_putstr(s));
}

int	print_dec(va_list args, t_opt *opt)
{
	char	result[32];
	int		n;
	int 	count;
	char	*s;

	n = va_arg(args, int);
	if (n < 0)
		s = convert(result, 1, -(unsigned long)(n), "0123456789");
	else
		s = convert(result, 0, n, "0123456789");
	return (ft_putstr(s));
}

void print_alt(int *count, t_opt *opt, char *alt, unsigned int n)
{
	if (opt->alt && n)
		*count += ft_putstr(alt);
}	

int	print_hex_cap(va_list args, t_opt *opt)
{
	char			result[32];
	unsigned int	n;
	int 			count;
	char			*s;

	n = va_arg(args, unsigned int);
	print_alt(&count, opt, "0X", n);
	s = convert(result, n < 0, n, "0123456789ABCDEF");
	count = 0;
	print_alt(&count, opt, "0x", n);
	count += ft_putstr(s);
	return (count);
}

int	print_hex(va_list args, t_opt *opt)
{
	char			result[32];
	unsigned int	n;
	int 			count;
	char			*s;

	n = va_arg(args, unsigned int);
	s = convert(result, n < 0, n, "0123456789abcdef");
	count = 0;
	print_alt(&count, opt, "0x", n);
	count += ft_putstr(s);
	return (count);
}

int	print_addr(va_list args, t_opt *opt)
{
	char			result[32];
	unsigned long	n;
	int 			count;
	char			*s;

	n = va_arg(args, unsigned long);
	s = convert(result, 0, n, "0123456789abcdef");
	*(--s) = 'x';
	*(--s) = '0';
	return (ft_putstr(s));
}
int print_mod(va_list args, t_opt *opt)
{
	return (ft_putchar('%'));
}