/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabounou <rabounou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:24:28 by rabounou          #+#    #+#             */
/*   Updated: 2024/11/22 10:24:48 by rabounou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define OPEN_MAX 10240

typedef struct s_buf
{
	char	*b_tmp;
	char	str[2048];
	size_t	idx;
}			t_buf;

char		*get_next_line(int fd);
size_t		ft_strlen(char *s);
char		*ft_strdup(char *s);
void		appendto_buffer(char *tmp, t_buf *buffer, char **line);
char		*last_clean(char *s, void (*f)(void *));
int			nl_found(char *s);
void		appendto_line(char **line, char *buffer);

#endif
