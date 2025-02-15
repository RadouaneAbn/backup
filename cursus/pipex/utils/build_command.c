#include "../includes/utils.h"

static char	*append_path_to_command(char *cmd, char *path)
{
	int		rlen;
	char	*cmd_path;

	rlen = ft_strlen(path) + ft_strlen(cmd) + 2;
	cmd_path = malloc(rlen * sizeof(char));
	cmd_path[0] = 0;
	ft_strcat(cmd_path, path);
	ft_strcat(cmd_path, "/");
	ft_strcat(cmd_path, cmd);
	return (cmd_path);
}

static char	* find_command(char *cmd, char **path)
{
	int		i;
	char	*tmp;

	if (path == NULL)
		return (cmd);
	i = 0;
	while (path[i])
	{
		tmp = append_path_to_command(cmd, path[i]);
		if (file_exists(tmp))
			return (free(cmd), tmp);
		free(tmp);
		i++;
	}
	return (cmd);
}

static char	**ft_path_join(char **cmd_v, char **path)
{
	if (ft_strchr(cmd_v[0], '/') == NULL &&
		ft_strncmp(cmd_v[0], ".", 2) != 0 &&
		ft_strncmp(cmd_v[0], "..", 3) != 0)
		cmd_v[0] = find_command(cmd_v[0], path);
	return (cmd_v);
}

char	**build_command(char *full_command, char **path)
{
	char **cmd_v;

	cmd_v = ft_split(full_command, ' ');
	cmd_v = ft_path_join(cmd_v, path);
	return (cmd_v);
}