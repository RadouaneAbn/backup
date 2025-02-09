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
	char	*new_cmd_path;
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
char	**ft_path_join(char ***cmd_v, char **path)
{
	int		i;
	char	*new_path_cmd;

	i = 0;
	if (ft_strchr((*cmd_v)[0], '/') == NULL)
		(*cmd_v)[0] = find_command((*cmd_v)[0], path);
	if (file_exists((*cmd_v)[0]) == 0)
		print_error((*cmd_v)[0], ": command not found\n");
    else if (file_executable((*cmd_v)[0]) == 0)
		print_error((*cmd_v)[0], ": Permission denied\n");
    return (*cmd_v);
}

char	**build_command(char *full_command, char **path)
{
	char	**cmd_v;
	int		i;

	i = 0;
	cmd_v = ft_split(full_command, ' ');
	ft_path_join(&cmd_v, path);
	return (cmd_v);
}

void	pipex(int ac, char **av, char **env, int cmd_count)
{
	char	**path;
	char	**command;
	int		i;
	int		pid;
	int		fd[2];
    int     input_fd;

	path = export_path_var(env);
	i = 2;
	input_fd = open_input_file(av[1]);
    if (input_fd == -1)
    {
        input_fd = open("/dev/null", O_RDONLY);
        i++;
    }
	while (i < cmd_count)
	{
        command = build_command(av[i], path);
        if (i < cmd_count - 1)
            pipe(fd);
        pid = fork();
        if (pid == 0)
        {
            dup2(input_fd, STDIN_FILENO);
            close(input_fd);
            if (i < cmd_count - 1)
            {
                dup2(fd[1], STDOUT_FILENO);
                close(fd[1]);
                close(fd[0]);
            }
            execve(command[0], command, env);
        }
        free_command(command);
        close(input_fd);
        if (i < cmd_count - 1)
        {
            input_fd = fd[0];
            close(fd[1]);
        }
		i++;
	}

    while (wait(NULL) > 0)
        ;
    
}

int	main(int ac, char **av, char **env)
{
	if (ac < 5)
	{
		printf("Wrong format: %s input_file cmd1 cmd2 output_file\n", av[0]);
		exit(1);
	}
	pipex(ac, av, env, ac - 1);
    free_all();
	return (0);
}
