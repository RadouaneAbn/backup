#include "../includes/garbage_collector.h"
#include "../includes/pipex.h"
#include "../includes/utils.h"

int	ft_strcat(char *dest, const char *src)
{
	int	dest_len;
	int	i;

	i = 0;
	if (dest == NULL || src == NULL)
		return (-1);
	dest_len = ft_strlen(dest);
	while (src[i])
	{
		dest[dest_len] = src[i];
		dest_len++;
		i++;
	}
	dest[dest_len] = 0;
	return (dest_len);
}

void	free_command(char **list)
{
	int	i;

	i = 0;
	while (list[i])
		free(list[i++]);
	free(list);
}
