#include "includes/pipex_bonus.h"

int	main(int ac, char **av, char **env)
{
	if (ac < 5)
	{
		printf("Wrong format: %s input_file cmd1 cmd2 ...[cmdn] output_file\n", av[0]);
		exit(1);
	}
    pipex(ac, av, env);
	return (0);
}