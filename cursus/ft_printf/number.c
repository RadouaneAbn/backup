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

int	print_udec(unsigned int n)
{
	char	result[12];
	int		i;

	i = 11;
	result[i--] = 0;
	if (n == 0)
		result[i--] = '0';
	while (n)
	{
		result[i--] = (n % 10) + '0';
		n /= 10;
	}
	return (print_str(result + i + 1));
}

int	print_dec(int n)
{
	char			result[12];
	int				is_signed;
	unsigned int	nn;
	int				i;

	is_signed = (n < 0);
	nn = (n < 0) * -n + (n >= 0) * n;
	if (is_signed)
		n *= -1;
	i = 11;
	result[i--] = 0;
	if (n == 0)
		result[i--] = '0';
	while (nn)
	{
		result[i--] = (nn % 10) + '0';
		nn /= 10;
	}
	if (is_signed)
		result[i--] = '-';
	return (print_str(result + i + 1));
}

int	print_hex(unsigned int n, char flag)
{
	char	result[12];
	int		c;
	int		i;
	char	cap;

	i = 11;
	cap = (flag == 'X') * 'A' + (flag == 'x') * 'a' ;
	result[i--] = 0;
	if (n == 0)
		result[i--] = '0';
	while (n)
	{
		c = n % 16;
		if (c < 10)
			result[i--] = c + '0';
		else
			result[i--] = cap + (c - 10);
		n /= 16;
	}
	return (print_str(result + i + 1));
}

int	print_addr(unsigned long n, char *base)
{
	char	result[22];
	int		c;
	int		i;

	i = 21;
	if (n == 0)
		return (print_str("(nil)"));
	result[i--] = 0;
	if (n == 0)
		result[i--] = '0';
	while (n)
	{
		c = n % 16;
		if (c < 10)
			result[i--] = c + '0';
		else
			result[i--] = base[c - 10];
		n /= 16;
	}
	result[i--] = 'x';
	result[i] = '0';
	return (print_str(result + i));
}
