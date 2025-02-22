/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabounou <rabounou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 22:32:52 by rabounou          #+#    #+#             */
/*   Updated: 2025/02/22 22:32:53 by rabounou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../includes/defs.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

# define PIPE 1
# define HEREDOC 2

void	pipex(int ac, char **av, char **env);
void	here_doc(int ac, char **av, char **env);
void	init_here_doc(t_execute_info *info, int ac, char **av, char **env);

#endif
