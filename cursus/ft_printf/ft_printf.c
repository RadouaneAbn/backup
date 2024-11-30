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

int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	print_char(int c)
{
	return (write(1, &c, 1));
}

int	print_str(char *s)
{
	if (s == NULL)
		return (write(1, "(null)", 6));
	return (write(1, s, ft_strlen(s)));
}

int print_hex_alt(unsigned int n, char flag)
{
	int count;

	count = 0;
	if (n != 0)
		count += print_str("0x");
	count += print_hex(n, flag);
	return (count);
}

int char_in_chaset(char c, char *set)
{
	while (*set)
	{
		if (*set == c)
			return (c);
		set++;
	}
	return (0);
}

int print_sign_space(int n, int opt)
{
	int count;

	count = 0;
	if (n >= 0)
		count += print_char(opt);
	count += print_dec(n);
	return (count);
}

int	ft_atoi_s(const char *str, int *i)
{
	int	result;

	result = 0;
	while (ft_isdigit(str[*i]))
	{
		result = result * 10 + str[*i] - '0';
		(*i)++;
	}
	return (result);
}

void get_options(const char *s, int *i, t_opt *opt)
{
	char current;

	current = 1;
	opt->leading_space_sign = 0;
	opt->pad = 0;
	opt->width = 0;
	opt->alt = 0;
	opt->precision = 0;
	while (current)
	{
		current = char_in_chaset(s[*i], "0.-+ #");
		if (current == 0)
			break;
		if (current == ' ' && opt->leading_space_sign != '+')
			opt->leading_space_sign = ' ';
		else if (current == '+')
			opt->leading_space_sign = '+';
		// if (s[i] )
	}
}

int	find_flag(va_list args, const char *s, int *i)
{
	// int start;
	t_opt options;

	(*i)++;
	get_options(s, i, &options);
	// start = *i;
	// while (char_in_chaset(s[*i], ".0- +#"))
	// if (s[*i] >= '0' && s[*i] <= '9')
	// 	width = ft_atoi(s, i);
	// if (s[*i] == '.')
	// 	precision = ft_atoi(s, i);
	// if (s[*i] == '-')
	// {
	// 	pad = 1;
	// 	(*i)++;
	// }

	if (s[*i] == '%')
		return (print_char('%'));
	else if (s[*i] == 'c')
		return (print_char(va_arg(args, int)));
	else if (s[*i] == 's')
		return (print_str(va_arg(args, char *)));
	else if (s[*i] == 'i' || s[*i] == 'd')
		return (print_dec(va_arg(args, int)));
	else if (s[*i] == 'u')
		return (print_udec(va_arg(args, unsigned int)));
	else if (s[*i] == 'x' || s[*i] == 'X')
		return (print_hex(va_arg(args, unsigned int), s[*i]));
	else if (s[*i] == 'p')
		return (print_addr(va_arg(args, unsigned long), "abcdef"));
	return (2);
}

// void build_func(t_func **functions)
// {
// 	functions[0]->flag = 'c';
// 	functions[1]->flag = 's';
// 	functions[2]->flag = 'i';
// 	functions[3]->flag = 'd';
// 	functions[4]->flag = 'u';
// 	functions[5]->flag = 'x';
// 	functions[6]->flag = 'X';
// 	functions[7]->flag = 'p';
// 	functions[7]->flag = 0;
// 	/*-------------------*/
// 	functions[0]->f = print_char;
// 	functions[1]->f = print_str;
// 	functions[2]->f = print_dec;
// 	functions[3]->f = print_dec;
// 	functions[4]->f = print_udec;
// 	functions[5]->f = print_hex;
// 	functions[6]->f = print_hex;
// 	functions[7]->f = NULL;
// }

// int find_flag(va_list args, const char *s, int *i, t_func *functions)
// {
// 	int n;

// 	n = 0;
// 	while (functions[n].flag != 0)
// 	{
// 		if (s[* i + 1] == functions[n].flag)
// 			return (functions[n].f(args, s, i));
// 	}
// 	return (0);
// }

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;
	// t_func functions[9];

	va_start(args, str);
	if (str == NULL)
		return (-1);
	i = 0;
	count = 0;
	// build_func(&functions);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
			count += find_flag(args, str, &i);
		else
			count += print_char(str[i]);
		i++;
	}
	return (count);
}
