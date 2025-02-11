#include "../includes/garbage_collector.h"
#include "../includes/pipex.h"
#include "../includes/utils.h"


char *append_path_to_command(char *cmd, char *path)
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

char	*find_command(char *cmd, char **path)
{
	int		i;
	char *tmp;

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

int command_executable(char **cmd_v, int *status)
{
	if (file_exists(cmd_v[0]) == 0)
	{
		print_error(cmd_v[0], ": command not found\n");
		*status = 127;
		return (0);
	}
	if (file_executable(cmd_v[0]) == 0)
	{
		print_error(cmd_v[0], ": Permission denied\n");
		*status = 126;
		return (0);
	}
	return (1);
}

char	**ft_path_join(char **cmd_v, char **path)
{
	if (ft_strchr(cmd_v[0], '/') == NULL)
		cmd_v[0] = find_command(cmd_v[0], path);
	return (cmd_v);
}

char	**build_command(char *full_command, char **path)
{
	char	**cmd_v;
	int		i;

	i = 0;
	cmd_v = ft_split(full_command, ' ');
	cmd_v = ft_path_join(cmd_v, path);
	return (cmd_v);
}

// void	pipex(int ac, char **av, char **env)
// {
// 	char	**path;
// 	char	**command;
// 	int		i;
// 	int		pid;
// 	int		fd[2];
// 	int     input_fd;
// 	int     output_fd;
// 	int    cmd_count;
// 	int status;

// 	cmd_count = ac - 1;
// 	path = export_path_var(env);
// 	i = 2;
// 	while (i < cmd_count)
// 	{
// 		if (i < cmd_count - 1)
// 			pipe(fd);
// 		pid = fork();
// 		if (pid == 0)
// 		{
// 			if (i == 2)
// 				input_fd = open_input_file(av[1]); 
// 			if (input_fd == -1)
// 				exit(1);
// 			dup2(input_fd, STDIN_FILENO);
// 			close(input_fd);
// 			command = build_command(av[i], path);
// 			if (i < cmd_count - 1)
// 			{
// 				close(fd[0]);
// 				dup2(fd[1], STDOUT_FILENO);
// 				close(fd[1]);
// 			}
// 			else
// 			{
// 				output_fd = open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
// 				dup2(output_fd, STDOUT_FILENO);
// 				close(output_fd);
// 			}
// 			if (command_executable(command, &status))
// 				execve(command[0], command, env);
// 			else
// 				free_command(command), free_all(), exit(status);
// 		}
// 		input_fd = fd[0];
// 		i++;
// 	}
// 	i = -1;
// 	// while (wait(NULL) > 0) ;
// 	//NOTICE: close the pipe before the wait
// 	while (++i < ac - 3)
// 		 wait(NULL);
// 	close(fd[0]);
// 	close(fd[1]);
// 	close(input_fd);
// 	 //waitpid(pid, &status, 0);
// 	// printf("[%d]\n", status);
// 	// if (status != 0)
// 	// 	free_all(), exit(status);
// }
void child_execute(char **env, int command_index, char **commands, int out, int in, char **path)
{
	int status;
	char **command = build_command(commands[command_index], path);

	dup2(in, STDIN_FILENO);
	close(in);
	dup2(out, STDOUT_FILENO);
	close(out);
	if (command_executable(command, &status))
		execve(command[0], command, env);
	else
		free_command(command), free_all(), exit(status);
}


void	pipex(int ac, char **av, char **env)
{
	char	**path;
	char 	**commands;
	int     pids[1024] = {0};
	int		i;
	int		fd[2];
	int     in;
	int     out;
	int		prev;
	int    cmd_count;

	cmd_count = (ac - 3);
	prev = -1;
	path = export_path_var(env);
	i = 0;
	commands = av + 2;
	in = open_input_file(av[1]);
	out = open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644); 
	while (i < cmd_count)
	{
		pipe(fd);
		pids[i] = fork();
		if (pids[i] == 0)
		{
			int status;
			char **command = build_command(commands[i], path);

			if (i == 0) {
				dup2(n, STDIN_FILENO);
				close(in);
			}
			else
				dup2(prev, STDIN_FILENO);
			if (i == cmd_count - 1)
			{
				dup2(out, STDOUT_FILENO);
				close(out);
			}
			else
				dup2(fd[1], STDOUT_FILENO);
			if (prev != 0)
				close(prev);
			close(fd[0]);
			close(fd[1]);
			if (command_executable(command, &status))
				execve(command[0], command, env);
			else
				free_command(command), free_all(), exit(status);
		}
		if (prev != -1)
			close(prev);
		prev = fd[0];
		close(fd[1]);
		i++;
	}
	close(in);
	close(prev);
	close(out);
	i = 0;
	while (pids[i])
		waitpid(pids[i++], NULL, 0);
}

int	main(int ac, char **av, char **env)
{
	if (ac < 5)
	{
		printf("Wrong format: %s input_file cmd1 cmd2 output_file\n", av[0]);
		exit(1);
	}
	pipex(ac, av, env);
	free_all();
	return (0);
}
