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

int	ft_printf(const char *str, ...);
int	ft_putudec(unsigned int n);
int	ft_putdec(int n);
int	ft_puthex(unsigned int n, char *base, int alt, char flag);
int	ft_putaddr(unsigned long n, char *base);
int	ft_putchar(int c);
int	ft_strlen(char *s);
int	ft_putstr(char *s);

#endif
