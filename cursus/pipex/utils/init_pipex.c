/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabounou <rabounou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 22:34:25 by rabounou          #+#    #+#             */
/*   Updated: 2025/02/22 22:34:28 by rabounou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/defs.h"
#include "../includes/utils.h"

void	init_here_doc(t_execute_info *info, int ac, char **av, char **env)
{
	info->commands_list = av + 3;
	info->current_command = NULL;
	info->output_file = av[ac - 1];
	info->path = export_path_var(env);
	info->delimiter = av[2];
	pipe(info->fd[0]);
	pipe(info->fd[1]);
}

void	init_pipex(t_cmd_v *commands, t_fd_holder *file_descriptors, char **av,
		int ac)
{
	commands->commands_list = av + 2;
	commands->current_command = NULL;
	commands->command_count = ac - 3;
	file_descriptors->input_file = av[1];
	file_descriptors->output_file = av[ac - 1];
	file_descriptors->prev = -1;
}
