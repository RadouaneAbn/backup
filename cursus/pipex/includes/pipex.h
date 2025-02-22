/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabounou <rabounou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 22:32:39 by rabounou          #+#    #+#             */
/*   Updated: 2025/02/22 22:32:40 by rabounou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../includes/defs.h"
# include "../libft/libft.h"

void	free_command(char **list);
void	print_error(char *name, char *error);
void	print_perror(char *name);
char	*find_path(char **env);
char	**export_path_var(char **env);
int		open_input_file(char *filename);
int		file_exists(char *file_path);
int		file_executable(char *file_path);
int		ft_strcat(char *dest, const char *src);

#endif
