#include "../includes/garbage_collector.h"
#include "../includes/utils.h"

void	pipex(int ac, char **av, char **env)
{
	t_cmd_v commands;
	t_fd_holder file_descriptors;
	int *pid;
	int i;

	pid = make_pid_array(ac - 3);
	init_pipex(&commands, &file_descriptors, av, ac);
	commands.path = export_path_var(env);
	i = 0;
	while (i < commands.command_count)
	{
		if (i != commands.command_count - 1)
			pipe(file_descriptors.fd);
		pid[i] = fork();
		if (pid[i] == 0)
			run_child_proccess(&commands, &file_descriptors, i, env);
		if (file_descriptors.prev != -1)
			close(file_descriptors.prev);
		file_descriptors.prev = file_descriptors.fd[0];
		close(file_descriptors.fd[1]);
		i++;
	}
	wait_for_children(pid);
	close(file_descriptors.prev);
}
