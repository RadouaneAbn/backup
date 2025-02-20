#include "../includes/garbage_collector.h"
#include "../includes/pipex_bonus.h"
#include "../includes/utils.h"

void	pipex(int ac, char **av, char **env)
{
	t_cmd_v		commands;
	t_fd_holder	file_descriptors;
	int			*pid;
	int			i;

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
		if (i != commands.command_count - 1)
			close(file_descriptors.fd[1]);
		i++;
	}
	wait_for_children(pid); /* NOTIC: close(file_descriptors.fd[0]); */
	close(file_descriptors.prev);
}

int	check_type(char **av)
{
	int	pipe_type;

	pipe_type = PIPE;
	if (ft_strncmp(av[1], "here_doc", 9) == 0)
		pipe_type = HEREDOC;
	return (pipe_type);
}

int	input_check(int ac, char **av)
{
	int	type;

	if (ac < 5)
		print_usage_error(BONUS_PART, av[0]);
	type = check_type(av);
	if ((type == PIPE && ac < 5) || (type == HEREDOC && ac != 6))
		print_usage_error(BONUS_PART, av[0]);
	return (type);
}

int	main(int ac, char **av, char **env)
{
	int pipe_type;

	pipe_type = input_check(ac, av);
	if (pipe_type == PIPE)
		pipex(ac, av, env);
	else
		here_doc(ac, av, env);
	return (0);
}