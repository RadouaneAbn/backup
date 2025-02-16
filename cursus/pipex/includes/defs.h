#ifndef DEFS_H
# define DEFS_H


# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_cmd_list
{
	char	***cmd_list;
	int		cmd_count;
}			t_cmd_list;

typedef struct s_cmd_v
{
	char	**commands_list;
	char	**current_command;
	char	**path;
	int		command_count;
}			t_cmd_v;

typedef struct s_fd_holder
{
	int		fd[2];
	int		prev;
	char	*input_file;
	char	*output_file;
}			t_fd_holder;

typedef struct s_execute_info
{
	int fd[2][2];
	char *output_file;
	char **path;
	char **commands_list;
	char **current_command;
	char *delimiter;
} t_execute_info;

enum
{
	MALLOC_R,
	READ_ERR,
	OPEN_ERR,
	DIR_ERR
};

#endif
