#ifndef FT_ASPRINTF_BONUS_H
# define FT_ASPRINTF_BONUS_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# include "../../src/libft/libft.h"

# define BUFFER_SIZE 1024
# define SUCCESS 0
# define FAILURE 1

typedef struct s_opt
{
	int		width;
	int		pad;
	int		alt;
	char	leading_space_sign;
	int		fill;
	int		precision[2];
}			t_opt;

typedef struct s_func
{
	char	flag;
	int		(*f)(va_list, t_opt *);
}			t_func;

typedef struct s_buffer
{
	char *result;
	char buf[BUFFER_SIZE];
	int i;
} t_buffer;

typedef struct s_params
{
	char *s;
	va_list args;
	t_func functions[10];
	t_buffer buffer;
}	t_params;

typedef struct s_str_len
{
	char *s;
	int slen;
} t_str_len;

char *ft_asprintf(const char *str, ...);

int append_string_to_buffer(t_buffer *buffer, char *s);
int append_char_to_buffer(t_buffer *buffer, char c);

/* FORMAT SPECIFIER FUNCTIONS */
int	copy_str(t_buffer *buffer, va_list args, t_opt *opt);
int	copy_char(t_buffer *buffer, va_list args, t_opt *opt);
int	copy_dec(t_buffer *buffer, va_list args, t_opt *opt);
int	copy_udec(t_buffer *buffer, va_list args, t_opt *opt);
int	copy_hex(t_buffer *buffer, va_list args, t_opt *opt);
int	copy_hex_cap(t_buffer *buffer, va_list args, t_opt *opt);


/* BUFFER OPERATIONS */
int	copy_precision(t_buffer *buffer, int precision);
int	copy_to_buffer(t_buffer *buffer, t_opt *opt, char *s, int slen);
int	copy_to_buffer_2(t_buffer *buffer, t_opt *opt, t_str_len str, int sign);
int	copy_filler(t_buffer *buffer, char c, int cond, int n);


/* UTILS */
int	char_in_chaset(char c, char *set);
char	*convert(char *result, int sign_space, unsigned long n, char *base);
int	copy_number(t_buffer *buffer, char *s, t_opt *opt);

#endif