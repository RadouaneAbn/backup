#include "../includes/garbage_collector.h"
#include "../includes/utils.h"

void	clean_exit(int exit_code)
{
	free_all();
	exit(exit_code);
}

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
		write(2, str, i);
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

void	exit_error(char *name, int error_code, int exit_code)
{
	if (error_code == MALLOC_R)
		print_error(name, ": malloc failed!\n");
	else if (error_code == DIR_ERR)
		print_error(name, ": is a directory\n");
	else if (error_code == PERMISSION_ERR)
		print_error(name, ": permission denied\n");
	else if (error_code == COMMAND_ERR)
		print_error(name, ": command not found\n");
	clean_exit(exit_code);
}
