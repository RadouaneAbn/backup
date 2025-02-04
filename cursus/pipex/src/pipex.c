#include "../includes/pipex.h"

char *find_path(char **env) {
    int i = 0;

    while (env[i]) {
        if (strncmp(env[i], "PATH", 4) == 0)
            return (env[i]);
        i++;
    }
    return (NULL);
}

int	ft_strcat(char *dest, const char *src)
{
	int	dest_len;
	int	i = 0;

    if (dest == NULL || src == NULL)
        return (-1);
	dest_len = ft_strlen(dest);
    while (src[i])
    {
        dest[dest_len] = src[i];
        dest_len++;
        i++;
    }
    dest[dest_len] = 0;
	return (dest_len);
}

char *append_path_cmd(char *path, char *cmd)
{
    int rlen = ft_strlen(path) + ft_strlen(cmd) + 2;
    char *cmd_path = malloc(rlen * sizeof(char));

    cmd_path[0] = 0;
    ft_strcat(cmd_path, path);
    ft_strcat(cmd_path, "/");
    ft_strcat(cmd_path, cmd);

    return (cmd_path);
}

char *create_path(char **path, char *cmd)
{
    int i = 0;
    char *s;

    if (access(cmd, F_OK | X_OK) == 0)
	return (cmd);

    while (path[i])
    {
        s = append_path_cmd(path[i], cmd);
        if (access(s, F_OK | X_OK) == 0)
        {
            // printf("%s\n", s);
            break;
        }
        free(s);
        i++;
    }
    free(cmd);
    return (s);
}

char **build_command(char *cmd, char **path)
{
    char **cmd_parsed;

    cmd_parsed = ft_split(cmd, ' ');
    cmd_parsed[0] = create_path(path, cmd_parsed[0]);

    // execve(cmd_parsed[0], cmd_parsed, env);
    return (cmd_parsed);
}

char **create_path_var(char **env)
{
	char *path_str;
	char **path;

	path_str = find_path(env);
	path = ft_split(path_str + 5, ':');
	return (path);
}

void creat_command_list(char ***commands, char **path, char **av, int ac)
{
	int i = 2;
	int cmd_idx = 0;
	while (i < ac - 1) {
		commands[cmd_idx++] = build_command(av[i], path);
		i++;
	}
	commands[cmd_idx] = NULL;
	// printf("count: %d\n", cmd_idx);
}

int main(int ac, char **av, char **env)
{
	if (ac < 5) {
		printf("Wrong format: ./pipex file1 cmd1 cmd2 file2\n");
		exit(1);
	}
	char ***commands = malloc((ac - 2) * sizeof(char *));
	char **path = create_path_var(env);
	creat_command_list(commands, path, av, ac);
	int in = open("in", O_RDONLY);
	int id, id1, id2, id3, id4;
	char buf[5000];
	int i, j;
	// int fd[1024][2];
	int fd[2];
	int fd_in;

	i = 0;
	/*
		Use an old_read_end_pipe istead of using an array to store the value of
		the read end file descriptor to be used in the nest command (iteration)
	*/
	int n = ac - 3;
	fd_in = in;
	while (i < n)
	{
		if (i < n - 1)
			pipe(fd);
		id = fork();
		if (id == 0)
		{
			dup2(fd_in, STDIN_FILENO);
			dup2(fd[1], STDOUT_FILENO);
			close(fd[1]);
			close(fd_in);
			// if (i < n - 1)
			// {
			// 	dup2(fd[1], STDOUT_FILENO);
			// 	close (fd[1]);
			// }
			// if (i == 0)
			// {
			// 	dup2(in, STDIN_FILENO);
			// 	// close (fd[0]);
			// 	close (in);
			// }
			// else if (i > 0)
			// {
			// 	dup2(fd[0], STDIN_FILENO);
			// 	close(fd[0]);
			// }
			// if (i < n - 1)
			// 	close (fd[0]);
			execve(commands[i][0], commands[i], env);
		}
		// if (i < n - 1)
		// 	close(fd[1]);
		// if (i > 0)
		// 	close(fd[0]);
		close(fd_in);
		fd_in = fd[0];
		i++;
	}

	close(in);

	clean_all(commands, path);


}
/*
int main(int ac, char **av, char **env)
{
	// t_cmd_list *commands = malloc(sizeof(t_cmd_list));
	// ft_bzero(commands, sizeof(t_cmd_list));
	if (ac < 5) {
		printf("Wrong format: ./pipex file1 cmd1 cmd2 file2\n");
		exit(1);
	}
	char ***commands = malloc((ac - 2) * sizeof(char *));
	char **path = create_path_var(env);
	creat_command_list(commands, path, av, ac);
	int in = open("in", O_RDONLY);
	int id, id1, id2, id3, id4;
	char buf[5000];
	int i, j;
	int fd[5][2];

	
	pipe(fd[0]);
	id1 = fork();
	if (id1 == 0) {
		dup2(fd[0][1], STDOUT_FILENO);
		dup2(in, STDIN_FILENO);
		close(fd[0][0]);
		close(fd[0][1]);
		execve(commands[0][0], commands[0], env);
	}

	close(fd[0][1]);
	// fd[0][0] is still open

	pipe(fd[1]);
	id2 = fork();
	if (id2 == 0) {
		dup2(fd[0][0], STDIN_FILENO);
		dup2(fd[1][1], STDOUT_FILENO);
		close(fd[0][0]);
		close(fd[1][0]);
		close(fd[1][1]);
		execve(commands[1][0], commands[1], env);
	}

	close(fd[0][0]);
	close(fd[1][1]);
	// fd[1][0] is still open

	pipe(fd[2]);
	id3 = fork();
	if (id3 == 0) {
		dup2(fd[1][0], STDIN_FILENO);
		dup2(fd[2][1], STDOUT_FILENO);
		close(fd[1][0]);
		close(fd[2][0]);
		close(fd[2][1]);
		execve(commands[2][0], commands[2], env);
	}

	close(fd[1][0]);
	close(fd[2][1]);
	// fd[2][0] is still open


	// pipe(fd[2]);
	id4 = fork();
	if (id4 == 0) {
		// dup2(fd[2][1], STDOUT_FILENO);
		dup2(fd[2][0], STDIN_FILENO);
		close(fd[2][0]);
		execve(commands[3][0], commands[3], env);
	}

	close(fd[2][0]);

	wait(NULL);
	wait(NULL);
	wait(NULL);
	wait(NULL);

	clean_all(commands, path);
	// pipe(fd);
	// id3 = fork();
	// if (id3 == 0) {
	// 	// dup2(fd[1], 1);
	// 	dup2(fd[0], 0);
	// 	execve(commands[2][0], commands[2], env);
	// }

	// id4 = fork();
	// if (id4 == 0) {
	// 	// dup2(fd[1], 1);
	// 	dup2(fd[0], 0);
	// 	execve(commands[2][0], commands[2], env);
	// }

	// printf("%s\n", buf);
}
*/
