#include <stdlib.h>

void	*ft_memset(void *data, int c, size_t len)
{
	unsigned char	*s;

	s = (unsigned char *) data;
	while (len > 0)
	{
		*s = ((unsigned char) c);
		s++;
		len--;
	}
	return (data);
}

void *ft_bzero(void *data, size_t size)
{
    return (ft_memset(data, 0, size));
}