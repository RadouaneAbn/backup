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

int main(int ac, char **av, char **env)
{
	if (ac != 5)
	{
		printf("Wrong format: ./pipex file1 cmd1 cmd2 file2\n");
		exit(1);
	}
	char **path = ft_split(find_path(env) + 5, ':');
	char **cmd1 = build_command(av[2], path);
	char **cmd2 = build_command(av[3], path);

	char **arr[2] = {cmd1, cmd2};
	int id;
	int i = 0;
	int fd[2];
	char buf[5000];
	int ss;
	pipe(fd);
	while (i < 2) {
		id = fork();
		if (id == 0) {
			dup2(fd[1], 1);
			dup2(0, fd[0]);
			execve(arr[i][0], arr[i], env);
		} else {
			wait(NULL);
			close(fd[1]);
			ss = read(fd[0], buf, 5000);
			buf[ss] = 0;
		}
		i++;
	}
	printf("%s\n", buf);
}
