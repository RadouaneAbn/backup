/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabounou <rabounou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:50:56 by rabounou          #+#    #+#             */
/*   Updated: 2024/11/28 16:50:58 by rabounou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct
{
    int width;
    int pad;
    int alt;
    char leading_space_sign;
    int fill;
    int precision[2];
} t_opt;


typedef struct {
    char flag;
    int (*f)(va_list, t_opt *); 
} t_func;

int	ft_printf(const char *str, ...);
int	print_udec(va_list args, t_opt *opt);
int	print_dec(va_list args, t_opt *opt);
int	print_hex(va_list args, t_opt *opt);
int	print_addr(va_list args, t_opt *opt);
int	print_str(va_list args, t_opt *opt);
int	print_char(va_list args, t_opt *opt);
int ft_strlen(const char *s);
int	print_hex_cap(va_list args, t_opt *opt);
int ft_putchar(int c);
int	ft_isdigit(int c);
int print_mod(va_list args, t_opt *opt);
int	ft_putnbr(char *s, t_opt *opt, char filler);
int char_in_chaset(char c, char *set);
int	ft_putstr(char *s, t_opt *opt, char filler);
int	ft_putaddr(char *s, t_opt *opt, char filler);
int	print_filler(char c, int cond, int n);
int	print_precision(int precision);
int error_handle(int i);
int writer(int *count, char *s, int slen);

#endif
