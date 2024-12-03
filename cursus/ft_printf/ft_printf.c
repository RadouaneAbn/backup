/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabounou <rabounou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:50:16 by rabounou          #+#    #+#             */
/*   Updated: 2024/11/28 15:50:55 by rabounou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(va_list args, t_opt *opt)
{
	int	c;
	int	count;

	count = 0;
	c = va_arg(args, int);
	if (print_filler(&count, ' ', opt->pad == 0, opt->width - 1) == -1)
		return (-1);
	if (ft_putchar(c) == -1)
		return (-1);
	count++;
	if (print_filler(&count, ' ', opt->pad == 1, opt->width - 1) == -1)
		return (-1);
	return (count);
}

int	print_str(va_list args, t_opt *opt)
{
	char	*s;

	s = va_arg(args, char *);
	opt->fill = ' ';
	return (ft_putstr(s, opt));
}

void	get_options(const char *s, int *i, t_opt *opt)
{
	init_options(opt);
	while (char_in_chaset(s[*i], "0.-+ #") || ft_isdigit(s[*i]))
	{
		if (s[*i] == ' ' && opt->leading_space_sign != '+')
			opt->leading_space_sign = ' ';
		else if (s[*i] == '0')
			opt->fill = '0';
		else if (s[*i] == '+')
			opt->leading_space_sign = '+';
		else if (s[*i] >= '0' && s[*i] <= '9')
			opt->width = ft_atoi_s(s, i);
		else if (s[*i] == '.')
		{
			(*i)++;
			opt->precision[0] = 1;
			opt->precision[1] = ft_atoi_s(s, i);
		}
		else if (s[*i] == '#')
			opt->alt = 1;
		else if (s[*i] == '-')
			opt->pad = 1;
		(*i)++;
	}
}

int	find_flag(va_list args, const char *s, int *i, t_func(functions)[10])
{
	t_opt	options;
	int		n;

	// t_func *f;
	// int start;
	// start = *i;
	(*i)++;
	get_options(s, i, &options);
	// print_options(options);
	// return(0);
	n = 0;
	while (functions[n].flag)
	{
		if (s[*i] == functions[n].flag)
		{
			return (functions[n].f(args, &options));
		}
		n++;
	}
	return (0);
}

void	build_func(t_func (*functions)[10])
{
	(*functions)[0].flag = '%';
	(*functions)[1].flag = 'c';
	(*functions)[2].flag = 's';
	(*functions)[3].flag = 'i';
	(*functions)[4].flag = 'd';
	(*functions)[5].flag = 'u';
	(*functions)[6].flag = 'x';
	(*functions)[7].flag = 'X';
	(*functions)[8].flag = 'p';
	(*functions)[9].flag = 0;
	/*-------------------*/
	(*functions)[0].f = print_mod;
	(*functions)[1].f = print_char;
	(*functions)[2].f = print_str;
	(*functions)[3].f = print_dec;
	(*functions)[4].f = print_dec;
	(*functions)[5].f = print_udec;
	(*functions)[6].f = print_hex;
	(*functions)[7].f = print_hex_cap;
	(*functions)[8].f = print_addr;
	(*functions)[9].f = NULL;
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;
	t_func	functions[10];

	va_start(args, str);
	if (str == NULL)
		return (-1);
	i = 0;
	count = 0;
	build_func(&functions);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
			count += find_flag(args, str, &i, functions);
		else
			count += ft_putchar(str[i]);
		i++;
	}
	return (count);
}
