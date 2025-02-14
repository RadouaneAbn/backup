#include "../includes/defs.h"

void	init_pipex(t_cmd_v *commands, t_fd_holder *file_descriptors, char **av,
		int ac)
{
	commands->commands_list = av + 2;
	commands->current_command = NULL;
	commands->command_count = ac - 3;
	file_descriptors->input_file = av[1];
	file_descriptors->output_file = av[ac - 1];
	file_descriptors->prev = -1;
}