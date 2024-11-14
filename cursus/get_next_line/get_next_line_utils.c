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

char	*ft_append_str(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	size;
	char	*ptr;

    size = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	ptr = malloc(size * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
		ptr[j++] = s1[i++];
	i = 0;
	while (s2 && s2[i])
		ptr[j++] = s2[i++];
	ptr[j] = 0;
    // if (s1)
    //     free(s1);
    // if (s2)
    //     free(s2);
	return (ptr);
}

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