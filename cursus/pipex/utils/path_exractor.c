/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_exractor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabounou <rabounou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 22:34:38 by rabounou          #+#    #+#             */
/*   Updated: 2025/02/22 22:34:40 by rabounou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

static char	*find_path(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
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
