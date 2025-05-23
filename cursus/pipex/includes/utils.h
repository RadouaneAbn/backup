/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabounou <rabounou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 22:32:58 by rabounou          #+#    #+#             */
/*   Updated: 2025/02/22 22:32:59 by rabounou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../includes/defs.h"
# include "../libft/libft.h"

char	**ft_parser(char *s, char c);
void	clean_exit(int exit_code);
void	print_cmd_v(char **cmd_v);
void	ft_puts(char *s);
void	execute_command(char **cmdv, char **env);
void	run_first_command(char *input_file, int fd[2]);
void	run_last_command(char *output_file, int prev);
void	run_mid_command(int fd[2], int prev);
void	run_child_proccess(t_cmd_v *commands, t_fd_holder *file_descriptors,
			int i, char **env);
char	**export_path_var(char **env);
int		*make_pid_array(int commands_count);
void	wait_for_children(int *pid);
void	init_pipex(t_cmd_v *commands, t_fd_holder *file_descriptors, char **av,
			int ac);
int		file_is_directory(char *file_path);
int		command_executable(char **cmd_v, int *status);
int		open_input_file(char *filename);
int		file_exists(char *file_path);
int		file_executable(char *file_path);
char	**build_command(char *full_command, char **path);
int		ft_strcat(char *dest, const char *src);
void	print_error(char *name, char *error);
void	print_perror(char *name);
void	exit_error(char *name, int error_code, int exit_code);
int		file_missing_argument(char *filename);
int		file_missing(char *filename);
void	exit_error(char *name, int error_code, int exit_code);
void	print_usage_error(int type, char *filename);

#endif
