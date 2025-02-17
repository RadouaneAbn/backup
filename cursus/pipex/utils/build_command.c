#include "../includes/utils.h"

static char	*append_path_to_command(char *cmd, char *path)
{
	int		rlen;
	char	*cmd_path;

	rlen = ft_strlen(path) + ft_strlen(cmd) + 2;
	cmd_path = malloc(rlen * sizeof(char));
	if (cmd_path == NULL)
		return (NULL);
	cmd_path[0] = 0;
	ft_strcat(cmd_path, path);
	ft_strcat(cmd_path, "/");
	ft_strcat(cmd_path, cmd);
	return (cmd_path);
}

static char	*find_command(char *cmd, char **path)
{
	int		i;
	char	*tmp;

	if (path == NULL)
		return (cmd);
	i = 0;
	while (path[i])
	{
		tmp = append_path_to_command(cmd, path[i]);
		if (tmp == NULL)
			return (NULL);
		if (file_exists(tmp))
			return (free(cmd), tmp);
		free(tmp);
		i++;
	}
	return (cmd);
}

static char	**ft_path_join(char **cmd_v, char **path)
{
	if (cmd_v == NULL)
		return (NULL);
	if (cmd_v[0] && ft_strchr(cmd_v[0], '/') == NULL &&
		ft_strncmp(cmd_v[0], ".", 2) != 0 &&
		ft_strncmp(cmd_v[0], "..", 3) != 0)
		cmd_v[0] = find_command(cmd_v[0], path);
	return (cmd_v);
}

int empty_command(char *full_command, int *status, int *error)
{
	int i;

	i = 0;
	*status = 126;
	*error = PERMISSION_ERR;
	if (full_command[i] == 0)
		return (1);
	while (full_command[i])
	{
		if (full_command[i] != ' ')
			return (0);
		i++;
	}
	*status = 127;
	*error = COMMAND_ERR;
	return (1);
}

char	**build_command(char *full_command, char **path)
{
	char **cmd_v;
	int status;
	int error;

	// if (empty_command(full_command))
	// 	return (ft_split(full_command, '\0'));

	if (empty_command(full_command, &status, &error))
		exit_error(full_command, error, status);
	cmd_v = ft_split(full_command, ' ');
	cmd_v = ft_path_join(cmd_v, path);
	if (cmd_v == NULL)
		exit_error("Malloc", MALLOC_R, 1);
	return (cmd_v);
}
