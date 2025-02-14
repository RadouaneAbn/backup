#include "../includes/utils.h"

void	print_error(char *name, char *error)
{
	char	*str;
	int		slen;
	int		i;

	slen = ft_strlen(name) + ft_strlen(error) + 15;
	if (name == NULL || error == NULL)
		clean_exit(1);
	str = (char *)malloc(slen);
	if (str)
	{
		str[0] = 0;
		i = ft_strcat(str, "pipex: ");
		i += ft_strcat(str + i, name);
		i += ft_strcat(str + i, error);
		free(str);
	}
}

void	print_perror(char *name)
{
	char	*str;

	str = ft_strjoin("pipex: ", name);
	perror(str);
	free(str);
}
