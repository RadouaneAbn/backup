#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include "libft/libft.h"

# define BUFFER_SIZE 1048576

typedef struct s_buf {
    char s[BUFFER_SIZE];
    int i;
} t_buf;

int ft_printf(const char *str, ...);
void    append_dec(t_buf *buf, int n);
void    append_udec(t_buf *buf, unsigned int n);
void    append_hex(t_buf *buf, unsigned int n, char *base);
void	copyto_buffer(t_buf *buf, const char *src);

#endif