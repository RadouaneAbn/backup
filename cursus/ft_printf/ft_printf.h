#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include "libft/libft.h"

typedef struct s_buf {
    char s[1048576];
    int i;
} t_buf;

int ft_printf(const char *str, ...);
void    append_dec(t_buf *buf, int n);

#endif