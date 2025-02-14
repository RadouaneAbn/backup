#include "../includes/garbage_collector.h"
#include "../includes/pipex.h"
#include "../includes/utils.h"

void	pipex(int ac, char **av, char **env)
{
	t_cmd_v		commands;
	t_fd_holder	file_descriptors;
	int			*pid;
	int			i;

	i = 0;
	pid = make_pid_array(2);
	init_pipex(&commands, &file_descriptors, av, ac);
	commands.path = export_path_var(env);
	pipe(file_descriptors.fd);
	pid[i] = fork();
	if (pid[i] == 0)
		run_child_proccess(&commands, &file_descriptors, i, env);
	file_descriptors.prev = file_descriptors.fd[0];
	close(file_descriptors.fd[1]);
	i++;
	pid[i] = fork();
	if (pid[i] == 0)
		run_child_proccess(&commands, &file_descriptors, i, env);
	close(file_descriptors.prev);
	wait_for_children(pid);
}
