#include "get_next_line.h"

size_t ft_strlen(char *s)
{
    size_t len;

    len = 0;
    if (!s)
        return (0);
    while (*s)
    {
        len++;
        s++;
    }
    return (len);
}

int ft_appendto_buffer(char *s, t_buf *b, char **line)
{
	int i = 0;

	while (s[i] && b->idx < 1023)
	{
		b->buffer[(b->idx)++] = s[i];
		if (s[i++] == '\n')
			break;
	}
	b->buffer[b->idx] = 0;
	if (s[i] && s[i] != '\n' && b->idx == 1023)
	{
		// copy to line and clear buffer
		ft_append_str(line, b->buffer);
		b->idx = 0;
		return (ft_appendto_buffer(s + i, b, line));
	}

	return (0);
}

int ft_append_str(char **dest, char *src)
{
	size_t slen = ft_strlen(src);
	size_t dlen = ft_strlen(*dest);
	size_t i = 0;
	size_t j = 0;
	char *new;

	new = malloc(dlen + slen + 1);
	if (new == NULL)
		return (-1);
	while (*dest && (*dest)[i])
	{
		new[i] = (*dest)[i];
		i++;
	}
	while (src[j])
		new[i++] = src[j++];
	new[i] = 0;
	if (*dest)
		free(*dest);
	*dest = new;
	return (1);
}
