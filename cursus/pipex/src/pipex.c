#include "../includes/pipex.h"
#include "../includes/utils.h"
#include "../includes/garbage_collector.h"

void free_command(char **list)
{
    int i;

    i = 0;
    while (list[i])
        free(list[i++]);
    free(list);
}

void print_error(char *name)
{
    char *str;

    str = ft_strjoin("pipex: ", name);
    perror(str);
    free(str);
}

char *find_path(char **env)
{
    int i;

    i = 0;
    while (env[i])
    {
        if (ft_strncmp(env[i], "PATH", 4) == 0)
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
    path = ft_parser(pre_path + 5, ':');
    return (path);
}

int open_input_file(char *filename)
{
    if (access(filename, F_OK) == -1)
    {
        print_error(filename);
        return (1);
    }
    if (access(filename, R_OK) == -1)
    {
        print_error(filename);
        return (1);
    }
    return (0);
}

int file_exists(char *file_path)
{
    if (access(file_path, F_OK) == 0)
        return (1);
    return (0);
}

int file_executable(char *file_path)
{
    if (access(file_path, X_OK) == 0)
        return (1);
    return (0);
}


char *find_command(char *cmd, char **path)
{
    int i;
    char *new_cmd_path;

    i = 0;
    while (path[i])
    {
        
    }
}
char **ft_path_join(char ***cmd_v, char **path)
{
    int i;
    char *new_path_cmd;

    i = 0;
    if (ft_strchr((*cmd_v)[0], '/') == NULL)
    {
        new_path_cmd = find_command((*cmd_v)[0], path);
    }
        if (file_exists((*cmd_v)[0]) == 0 ||
            file_executable((*cmd_v)[0]) == 0)
        print_error((*cmd_v)[0]);
}

char **build_command(char *full_command, char **path)
{
    char **cmd_v;
    int i;

    i = 0;
    cmd_v = ft_split(full_command, ' ');
    ft_path_join(&cmd_v, path);
    return (cmd_v);
}

void pipex(int ac, char **av, char **env, int cmd_count)
{
    char **path;
    char **command;
    int i;
    int fd;

    path = export_path_var(env);
    i = 2;
    i += open_input_file(av[1]);
    while (i < cmd_count)
    {
        command = build_command(av[i], path);
        free_command(command);
        i++;
    }
}

int main(int ac, char **av, char **env)
{
    if (ac < 5)
    {
        printf("Wrong format: %s input_file cmd1 cmd2 output_file\n", av[0]);
        exit(1);
    }

    pipex(ac, av, env, ac - 1);
    return (0);
}