#include "../includes/defs.h"
#include "../includes/garbage_collector.h"
#include "../libft/libft.h"

int *make_pid_array(int commands_count)
{
    int *pids;
    int count;

    count = commands_count + 1;
    pids = ft_smalloc(sizeof(int) * count);
    ft_bzero(pids, sizeof(int) * count);
    return (pids);
}

void	wait_for_children(int *pid)
{
	int	status;
	int	i;

	i = 0;
	while (pid[i])
		waitpid(pid[i++], &status, 0);
	free_all();
	if (WIFEXITED(status))
		exit(WEXITSTATUS(status));
}
