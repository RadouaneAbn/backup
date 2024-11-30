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
// # include "libft/libft.h"

// typedef int (*func)(va_list, const char *, int *i);

// typedef struct {
//     char flag;
//     func f; 
// } t_func;

typedef struct
{
    int precision;
    int width;
    int pad;
    int alt;
    char leading_space_sign;
} t_opt;


int	ft_printf(const char *str, ...);
int	print_udec(unsigned int n);
int	print_dec(int n);
int	print_hex(unsigned int n, char flag);
int	print_addr(unsigned long n, char *base);
int	print_str(char *s);
int	print_char(int c);

#endif
