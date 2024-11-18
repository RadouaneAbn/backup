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
	// printf("\n[[[%d]]]\n", i);
	b->buffer[b->idx] = 0;
	if (s[i] && s[i] != '\n' && b->idx == 1023)
	{
		// copy to line and clear buffer
		// printf("Buffer limit reached\n");
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

// char	*ft_append_str(char *s1, char *s2)
// {
// 	size_t	i;
// 	size_t	j;
// 	size_t	size;
// 	char	*ptr;

//     size = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
// 	ptr = malloc(size * sizeof(char));
// 	if (!ptr)
// 		return (NULL);
// 	i = 0;
// 	j = 0;
// 	while (s1 && s1[i])
// 		ptr[j++] = s1[i++];
// 	i = 0;
// 	while (s2 && s2[i])
// 		ptr[j++] = s2[i++];
// 	ptr[j] = 0;
// 	return (ptr);
// }

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	slen;
	size_t	rlen;
	size_t	i;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start > slen)
		start = slen;
	if (start + len < slen)
		rlen = len + 1;
	else
		rlen = slen - start + 1;
	str = malloc(sizeof(char) * rlen);
	if (!str)
		return (NULL);
	i = 0;
	while (s[start + i] && i < rlen)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = 0;
	return (str);
}