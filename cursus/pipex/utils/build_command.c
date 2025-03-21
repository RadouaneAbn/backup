/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabounou <rabounou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 22:33:37 by rabounou          #+#    #+#             */
/*   Updated: 2025/02/22 22:38:38 by rabounou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (cmd_v[0] && ft_strchr(cmd_v[0], '/') == NULL)
		cmd_v[0] = find_command(cmd_v[0], path);
	return (cmd_v);
}

int	empty_command(char *full_command, int *status, int *error)
{
	int	i;

	i = 0;
	*status = 126;
	*error = PERM_EXIT;
	if (full_command[i] == 0)
		return (1);
	while (full_command[i])
	{
		if (full_command[i] != ' ')
			return (0);
		i++;
	}
	*status = 127;
	*error = COMD_EXIT;
	return (1);
}

char	**build_command(char *full_command, char **path)
{
	char	**cmd_v;
	int		status;
	int		error;

	if (empty_command(full_command, &status, &error))
		exit_error(full_command, error, status);
	cmd_v = ft_split(full_command, ' ');
	cmd_v = ft_path_join(cmd_v, path);
	if (cmd_v == NULL)
		exit_error("Malloc", MALC_EXIT, 1);
	return (cmd_v);
}
