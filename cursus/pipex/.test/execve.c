#include "header.h"

char *find_path(char **env) {
    int i = 0;

    while (env[i]) {
        if (strncmp(env[i], "PATH", 4) == 0)
            return (env[i]);
        i++;
    }
    return (NULL);
}

int main (int ac, char **av, char **env) {
    char *args[2];
    if (ac != 2) {
        printf("Format: ./execve <cmd>\n");
        exit(1);
    }

    char *path_var = find_path(env);
    char **path = ft_split(path_var + 5, ':');

    int i = 0;
    char *s;
    while (path[i]) {
        s = ft_strjoin(path[i], "/");
        s = ft_strjoin(s, av[1]);
        args[0] = s;
        args[1] = NULL;
        if (access(s, F_OK | X_OK)) {
            // printf("%s: not found\n", s);
        } else {
            execve(s, NULL, env);
            free(s);
            break;
        }
        free(s);
        i++;
    }

    return (0);
}