#include "../includes/garbage_collector.h"
#include "../includes/pipex.h"
#include "../includes/utils.h"

void	execute_command(char **cmdv, char **env)
{
	int	status;

	status = 1;
	if (command_executable(cmdv, &status))
	{
		if (execve(cmdv[0], cmdv, env) == -1)
			perror("execve");
	}
	free_command(cmdv);
	clean_exit(status);
}

void	first_command(char *input_file, int fd[2])
{
	int	input_fd;

	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	input_fd = open_input_file(input_file);
	if (input_fd == -1)
	{
		// close(fd[0]);
		exit_error(input_file, OPEN_ERR, 1);
	}
	dup2(input_fd, STDIN_FILENO);
	close(input_fd);
}

void	last_command(char *output_file, int prev)
{
	int	output_fd;
	
	dup2(prev, STDIN_FILENO);
	close(prev);
	if (file_is_directory(output_file))
		exit_error(output_file, DIR_ERR, 1);
	output_fd = open(output_file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (output_fd == -1)
		exit_error("Open", READ_ERR, 1);
	dup2(output_fd, STDOUT_FILENO);
	close(output_fd);
}

void	mid_command(int fd[2], int prev)
{
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	dup2(prev, STDIN_FILENO);
	close(prev);
}

void	run_child_proccess(t_cmd_v *commands, t_fd_holder *file_descriptors,
		int i, char **env)
{
	if (i == 0)
		first_command(file_descriptors->input_file, file_descriptors->fd);
	else if (i == commands->command_count - 1)
		last_command(file_descriptors->output_file, file_descriptors->prev);
	else
		mid_command(file_descriptors->fd, file_descriptors->prev);
	commands->current_command = build_command(commands->commands_list[i],
												commands->path);
	execute_command(commands->current_command, env);
}
