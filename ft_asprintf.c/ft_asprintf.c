#include "ft_asprintf.h"
#include "../../src/libft/libft.h"

int append_to_line(char **dst, char *src)
{
	char *tmp;
	int total_size;

	tmp = *dst;
	*dst = ft_strjoin(*dst, src);
	if (tmp)
		free(tmp);
	if (*dst == NULL)
		return (FAILURE);
	return (SUCCESS);
}

int append_string_to_buffer(t_buffer *buffer, char *s)
{
    size_t i;
	int status;

    i = 0;
	status = SUCCESS;
    while (s[i] && buffer->i < BUFFER_SIZE)
        buffer->buf[buffer->i++] = s[i++];
	buffer->buf[buffer->i] = 0;
    if (s[i] || buffer->i == BUFFER_SIZE)
    {
        status = append_to_line(&(buffer->result), buffer->buf) == FAILURE;
		buffer->i = 0;
		if (status == SUCCESS)
        	status = append_string_to_buffer(buffer, s + i);
    }
	return (status);
}

int append_char_to_buffer(t_buffer *buffer, char c)
{
	int status;

    buffer->buf[buffer->i++] = c;
	buffer->buf[buffer->i] = 0;
	status = SUCCESS;
    if (buffer->i == BUFFER_SIZE)
    {
        status = append_to_line(&(buffer->result), buffer->buf);
		buffer->i = 0;
    }
	return (status);
}



int	find_flag(t_params *params, char *s, int *i)
{
	t_opt	options;
	int		n;
	int		start;

	start = *i;
	(*i)++;
	get_options(s, i, &options);
	n = 0;
	while (params->functions[n].flag)
	{
		if (s[*i] == params->functions[n].flag)
		{
			return (params->functions[n].f(params->args, &options));
		}
		n++;
	}
	if (s[*i] == 0)
		return (-1);
	*i = start;
	return (copy_mod(params->args, &options));
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
	// (*functions)[0].f = print_mod;
	// (*functions)[1].f = print_char;
	// (*functions)[2].f = print_str;
	// (*functions)[3].f = print_dec;
	// (*functions)[4].f = print_dec;
	// (*functions)[5].f = print_udec;
	// (*functions)[6].f = print_hex;
	// (*functions)[7].f = print_hex_cap;
	// (*functions)[8].f = print_addr;
	(*functions)[9].f = NULL;
}

int	init_printf(const char *str, t_params *params)
{
	int	i;
	int	tmp;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			tmp = find_flag(params, str, &i);
		else
			tmp = append_char_to_buffer(params, str[i]);
		if (tmp == FAILURE)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

char *ft_asprintf(const char *str, ...)
{
	t_params params;

    if (str == NULL)
        return (NULL);
    params.buffer.i = 0;
    params.buffer.result = NULL;
    params.buffer.buf[0] = 0;
	va_start(params.args, str);
	build_func(&(params.functions));
	if (init_printf(str, &params) == FAILURE)
	{
		if (params.buffer.result)
			free(params.buffer.result);
		params.buffer.result = NULL;
	}
	va_end(params.args);
    return (params.buffer.result);
}