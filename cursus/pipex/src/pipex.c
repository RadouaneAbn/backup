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
/*
int main (int ac, char **av, char **env)
{
	char buf[5000];
	int size;
	if (ac != 2)
		return (0);
	int fd[2];
	pipe(fd);
	char **path = ft_split(find_path(env) + 5, ':');
	char **cmd_parsed = build_command(av[1], path);
	
	int id = fork();
	if (id == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		execve(cmd_parsed[0], cmd_parsed, env);
	}
	else
	{
		int f = open("test.txt", O_RDWR);
		//wait(NULL);
		size = read(fd[0], buf, 5000);
		buf[size] = 0;
		printf("%s\n", buf);
		write(f, buf, size);
	}
	printf("Done\n");
	return (0);
}*/

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
	// t_cmd_list *commands = malloc(sizeof(t_cmd_list));
	char ***commands = malloc((ac - 2) * sizeof(char *));
	// ft_bzero(commands, sizeof(t_cmd_list));
	if (ac < 5) {
		printf("Wrong format: ./pipex file1 cmd1 cmd2 file2\n");
		exit(1);
	}
	char **path = create_path_var(env);
	int i = 0;
	int j = 0;
	
	creat_command_list(commands, path, av, ac);
	// while (commands[i])
	// {
	// 	j = 0;
	// 	while (commands[i][j])
	// 		printf("%s ", commands[i][j++]);
	// 	printf("\n");
	// 	i++;
	// }
	// char **cmd1 = build_command(av[2], path);
	// char **cmd2 = build_command(av[3], path);
	int in = open("in", O_RDONLY);

	// char **arr[2] = {cmd1, cmd2};
	int id, id1, id2, id3, id4;
	// int i = 0;
	int fd[2];
	char buf[5000];
	int ss;

	i = 0;

	pipe(fd);
	// while (commands[i]) {
	// 	// printf("%s\n", commands[i][0]);
	// 	id = fork();
	// 	if (id == 0) {
	// 		if (commands[i + 1])
	// 			dup2(fd[1], 1);
	// 		if (i == 0)
	// 			dup2(in, 0);
	// 		else
	// 			dup2(fd[0], 0);
	// 		execve(commands[i][0], commands[i], env);
	// 	}
	// 	i++;
	// }
	// printf("reach: %d\n", i);

	pipe(fd);
	id1 = fork();
	if (id1 == 0) {
		dup2(fd[1], 1);
		dup2(in, 0);
		execve(commands[0][0], commands[0], env);
	}

	id2 = fork();
	if (id2 == 0) {
		// dup2(fd[1], 1);
		dup2(fd[0], 0);
		execve(commands[1][0], commands[1], env);
	}

	id3 = fork();
	if (id3 == 0) {
		// dup2(fd[1], 1);
		dup2(fd[0], 0);
		execve(commands[2][0], commands[2], env);
	}

	// id4 = fork();
	// if (id4 == 0) {
	// 	// dup2(fd[1], 1);
	// 	dup2(fd[0], 0);
	// 	execve(commands[2][0], commands[2], env);
	// }

	// printf("%s\n", buf);
}
