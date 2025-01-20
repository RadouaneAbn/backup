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

int main(int ac, char **av, char **env) {
    int i = 0;

    // while (env[i]) {
    //     printf("%d: %s\n", i + 1, env[i]);
    //     i++;
    // }

    char *path_var = find_path(env);

    char **path = ft_split(path_var + 5, ':');

    i = 0;
    printf("Prining the path variable:\n");
    while (path[i]) {
        printf("%-2d: %s\n", i + 1, path[i]);
        free(path[i]);
        i++;
    }

    free(path);

    return (0);
}