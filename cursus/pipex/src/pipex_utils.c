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

void	print_error(char *name, char *error)
{
	char	*str;
	int     slen;
	int		i;

	slen = ft_strlen(name) + ft_strlen(error) + 15;
	if (name == NULL || error == NULL)
		clean_exit(1);
	str = (char *) malloc(slen);
	if (str && name)
	{
		str[0] = 0;
		i = ft_strcat(str, "pipex: ");
		i += ft_strcat(str + i, name);
		i += ft_strcat(str + i, error);
		if (i != -1)
			write(2, str, i);
		free(str);
	}
	// else
	// 	clean_exit(1);
}

void	print_perror(char *name)
{
	char	*str;

	str = ft_strjoin("pipex: ", name);
	perror(str);
	free(str);
}

char	*find_path(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH", 4) == 0)
			return (env[i]);
		i++;
	}
	return (NULL);
}

char	**export_path_var(char **env)
{
	char	**path;
	char	*pre_path;

	if (env == NULL)
		return (NULL);
	pre_path = find_path(env);
	if (pre_path == NULL)
		return (NULL);
	path = ft_parser(pre_path + 5, ':');
	return (path);
}

int	open_input_file(char *filename)
{
	if (access(filename, F_OK) == -1)
	{
		print_perror(filename);
		return (-1);
	}
	if (access(filename, R_OK) == -1)
	{
		print_perror(filename);
		return (-1);
	}
	return (open(filename, O_RDONLY));
}

int	file_exists(char *file_path)
{
	if (access(file_path, F_OK) == 0)
		return (1);
	return (0);
}

int	file_executable(char *file_path)
{
    if (file_exists(file_path) == 0)
        return (0);
	if (access(file_path, X_OK) == 0)
		return (1);
	return (0);
}