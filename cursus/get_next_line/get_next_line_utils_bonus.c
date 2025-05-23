/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabounou <rabounou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:46:20 by rabounou          #+#    #+#             */
/*   Updated: 2024/11/21 15:46:22 by rabounou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	size_t	i;
	size_t	slen;
	char	*new;

	if (s == NULL)
		return (NULL);
	i = 0;
	slen = ft_strlen(s);
	new = malloc(slen + 1);
	if (new == NULL)
		return (NULL);
	while (s[i])
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

void	appendto_buffer(char *tmp, t_buf *buffer, char **line)
{
	int	i;

	i = 0;
	while (tmp[i] && buffer->idx < 2047)
	{
		buffer->str[(buffer->idx)++] = tmp[i];
		if (tmp[i++] == '\n')
			break ;
	}
	(buffer->str)[buffer->idx] = '\0';
	if (tmp[i] && buffer->idx == 2047)
	{
		appendto_line(line, buffer->str);
		buffer->idx = 0;
		appendto_buffer(tmp + i, buffer, line);
	}
}

char	*last_clean(char *s, void (*f)(void *))
{
	int		i;
	int		j;
	char	*last;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\0' || s[i + 1] == '\0')
		last = NULL;
	else
	{
		j = i + 1;
		last = ft_strdup(s + j);
	}
	if (f && s)
		f(s);
	return (last);
}

int	nl_found(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (s[i] == '\n');
}
