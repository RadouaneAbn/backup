#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>
#include <limits.h>

int ft_printf(const char *str, ...);
int    ft_putudec(unsigned int n);
int    ft_putdec(int n);
int    ft_puthex(unsigned int n, char *base);
int     ft_putaddr(unsigned long n, char *base);
int ft_putchar(int c);
int ft_strlen(char *s);
int ft_putstr(char *s);

#endif
