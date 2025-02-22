/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_management.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabounou <rabounou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 22:34:42 by rabounou          #+#    #+#             */
/*   Updated: 2025/02/22 22:34:43 by rabounou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/defs.h"
#include "../includes/garbage_collector.h"
#include "../includes/utils.h"
#include "../libft/libft.h"

int	*make_pid_array(int commands_count)
{
	int	*pids;
	int	count;

	count = commands_count + 1;
	pids = ft_smalloc(sizeof(int) * count);
	if (pids == NULL)
		exit_error("Malloc", MALC_EXIT, 1);
	ft_bzero(pids, sizeof(int) * count);
	return (pids);
}

void	wait_for_children(int *pid)
{
	int	status;
	int	i;

	i = 0;
	while (pid[i])
		waitpid(pid[i++], &status, 0);
	free_all();
	if (WIFEXITED(status))
		exit(WEXITSTATUS(status));
}
