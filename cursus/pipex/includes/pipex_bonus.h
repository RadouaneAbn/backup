#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/libft.h"
# include "../includes/defs.h"
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

# define PIPE 1
# define HEREDOC 2

void	pipex(int ac, char **av, char **env);
void	here_doc(int ac, char **av, char **env);
void	init_here_doc(t_cmd_v *commands, t_fd_holder *file_descriptors, char **av,
	int ac);


#endif
