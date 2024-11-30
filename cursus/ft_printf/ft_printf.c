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
	int c;

	c = va_arg(args, int);
	return (ft_putchar(c));
}


int	print_str(va_list args, t_opt *opt)
{
	char *s;

	s = va_arg(args, char *);
	return (ft_putstr(s));
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

// int print_sign_space(int n, int opt)
// {
// 	int count;

// 	count = 0;
// 	if (n >= 0)
// 		count += print_char(opt);
// 	count += print_dec(n);
// 	return (count);
// }

int	ft_atoi_s(const char *str, int *i)
{
	int	result;

	result = 0;
	while (ft_isdigit(str[*i]))
	{
		result = result * 10 + str[*i] - '0';
		(*i)++;
	}
	(*i)--;
	return (result);
}

void init_options(t_opt *opt)
{
	opt->leading_space_sign = 0;
	opt->pad = 0;
	opt->width = 0;
	opt->alt = 0;
	opt->precision = 0;
}

void get_options(const char *s, int *i, t_opt *opt)
{
	char current;

	init_options(opt);
	current = 1;
	while (current)
	{
		current = char_in_chaset(s[*i], "0.-+ #");
		if (current == 0)
			break;
		if (current == ' ' && opt->leading_space_sign != '+')
			opt->leading_space_sign = ' ';
		else if (current == '+')
			opt->leading_space_sign = '+';
		else if (s[*i] >= '0' && s[*i] <= '9')
			opt->width = ft_atoi_s(s, i);
		else if (s[*i] == '.')
		{
			(*i)++;
			opt->precision = ft_atoi_s(s, i);
		}
		else if (s[*i] == '#')
			opt->alt = 1;
		else if (s[*i] == '-')
			opt->pad = 1;
		(*i)++;
	}
}

int	find_flag(va_list args, const char *s, int *i, t_func (functions)[10])
{
	t_func *f;
	int start;
	t_opt options;
	int n;

	start = *i;
	(*i)++;
	get_options(s, i, &options);
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

void build_func(t_func (*functions)[10])
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
	t_func functions[10];

	va_start(args, str);
	if (str == NULL)
		return (-1);
	i = 0;
	count = 0;
	// printf("build pointer to functions...\n");
	build_func(&functions);
	// printf("[%c]\n", functions[1].flag);
	// printf("start itration\n");
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
// int print_hex_alt(unsigned int n, char flag)
// {
// 	int count;

// 	count = 0;
// 	if (n != 0)
// 		count += print_str("0x");
// 	count += print_hex(n, flag);
// 	return (count);
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

// int main() {
// 	char *s = "red";
// 	ft_printf("hello [%x]\n", 42);
// 	ft_printf("hello [%# x]\n", 42);
// 	printf("hello [% #x]\n", 42);
// }