/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabounou <rabounou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:23:09 by rabounou          #+#    #+#             */
/*   Updated: 2025/02/22 22:31:27 by rabounou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_buf
{
	char	*b_tmp;
	char	str[2048];
	size_t	idx;
}			t_buf;

char		*get_next_line(int fd);
void		appendto_buffer(char *tmp, t_buf *buffer, char **line);
char		*last_clean(char *s, void (*f)(void *));
int			nl_found(char *s);
void		appendto_line(char **line, char *buffer);

#endif
