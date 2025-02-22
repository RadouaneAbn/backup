/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_access.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabounou <rabounou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 22:34:15 by rabounou          #+#    #+#             */
/*   Updated: 2025/02/22 22:34:16 by rabounou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

int	file_exists(char *file_path)
{
	if (access(file_path, F_OK) == 0)
		return (1);
	return (0);
}

int	file_is_directory(char *file_path)
{
	int	file_fd;

	file_fd = open(file_path, __O_DIRECTORY);
	if (file_fd == -1)
		return (0);
	close(file_fd);
	return (1);
}

int	file_executable(char *file_path)
{
	if (file_exists(file_path) == 0)
		return (0);
	if (access(file_path, X_OK) == 0)
		return (1);
	return (0);
}

int	command_executable(char **cmd_v, int *status)
{
	if (file_missing_argument(cmd_v[0]))
		*status = 2;
	else if (file_missing(cmd_v[0]))
		*status = 127;
	else if (file_is_directory(cmd_v[0]))
	{
		print_error(cmd_v[0], ": Is a directory\n");
		*status = 126;
	}
	else if (file_executable(cmd_v[0]) == 0)
	{
		print_error(cmd_v[0], ": Permission denied\n");
		*status = 126;
	}
	else
		return (1);
	return (0);
}
