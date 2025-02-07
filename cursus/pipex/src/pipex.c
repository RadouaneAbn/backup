#include "../includes/pipex.h"

char *find_path(char **env)
{
    int i;

    i = 0;
    while (env[i])
    {
        if (ft_strncmp(env[i], "PATH", 4))
            return (env[i]);
        i++;
    }
    return (NULL);
}

char **export_path_var(char **env)
{
    char **path;
    char *pre_path;

    if (env == NULL)
        return (NULL);
    
    pre_path = find_path(env);
    if (pre_path == NULL)
        return (NULL);
    path = ft_split(pre_path + 5, ':');
    return (path);
}

int open_input_file(char *filename)
{
    if (access(filename, F_OK) == -1)
    {
        perror("F_OK");
        return (1);
    }
    if (access(filename, R_OK) == -1)
    {
        perror("R_OK");
        return (1);
    }
    return (0);
}

void pipex(int ac, char **av, char **env, int cmd_count)
{
    char **path;
    char **command;
    int i;
    int fd;

    path = export_path_var(env);
    i = open_input_file(av[1]);
    while (i < cmd_count)
    {
        command = build_command(av[1])
    }
}

int main(int ac, char **av, char **env)
{
    if (ac < 5)
    {
        printf("Wrong format: %s file1 cmd1 cmd2 file2\n", av[0]);
        exit(1);
    }

    pipex(ac, av, env, ac - 3);
    return (0);
}