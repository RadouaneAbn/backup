/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabounou <rabounou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 22:32:20 by rabounou          #+#    #+#             */
/*   Updated: 2025/02/22 22:32:22 by rabounou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFS_H
# define DEFS_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

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
	int		fd[2][2];
	char	*output_file;
	char	**path;
	char	**commands_list;
	char	**current_command;
	char	*delimiter;
}			t_execute_info;

enum
{
	MALC_EXIT = 1,
	DIRE_EXIT,
	PERM_EXIT,
	COMD_EXIT,
	FILE_EXIT,
	READ_EXIT,
	OPEN_EXIT,
	MANDATORY_PART,
	BONUS_PART
};

# define MALC_EM ": malloc failed!\n"
# define DIRE_EM ": is a directory\n"
# define PERM_EM ": permission denied\n"
# define COMD_EM ": command not found\n"
# define FILE_EM ": No such file or directory\n"
# define FARG_EM ": Filename argument required\n"
// # define READ_EM ": Permi"
// # define OPEN_EM ": Cannot open file"

#endif
