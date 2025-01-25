#include "../includes/pipex.h"

int clean_all(char ***cmds, char **path)
{
    int i;
    int j;

    i = 0;
	while (cmds[i])
    {
		j = 0;
		while (cmds[i][j]) {
			free(cmds[i][j]);
			j++;
		}
		free(cmds[i]);
		i++;
	}
	free(cmds);

	i = 0;
	while (path[i]) {
		free(path[i]);
		i++;
	}
	free(path);
	return (0);
}
