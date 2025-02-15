#include "includes/pipex_bonus.h"

int check_type(char **av)
{
	int pipe_type;

	pipe_type = PIPE;
	if (ft_strncmp(av[1], "here_doc", 9) == 0)
		pipe_type = HEREDOC;
	return (pipe_type);
}

int input_check(int ac, char **av)
{
	if (ac < 5)
	{
		printf("Wrong format: %s input_file cmd1 cmd2 ...[cmdn] output_file\n", av[0]);
		printf("            : %s here_doc LIMITER cmd cmd1 output_file\n", av[0]);
		exit(1);
	}
	return(check_type(av));
}

int	main(int ac, char **av, char **env)
{
	int pipe_type;

	pipe_type = input_check(ac, av);
	if (pipe_type == PIPE)
    	pipex(ac, av, env);
	else
		here_doc(ac, av, env);
	return (0);
}