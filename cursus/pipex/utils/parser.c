/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabounou <rabounou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:09:07 by rabounou          #+#    #+#             */
/*   Updated: 2024/10/25 22:11:51 by rabounou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/garbage_collector.h"
#include "../includes/utils.h"
#include "../libft/libft.h"

static size_t	get_word_count(char *s, char c, size_t slen)
{
	size_t	wcount;
	size_t	i;
	int		word_found;

	wcount = 0;
	word_found = 0;
	i = 0;
	while (i <= slen)
	{
		if (!word_found && (s[i] != c && s[i] != '\0'))
			word_found = 1;
		else if (word_found && (s[i] == c || s[i] == '\0'))
		{
			word_found = 0;
			wcount++;
		}
		i++;
	}
	return (wcount);
}

char	**free_array(char **words)
{
	int	i;

	i = 0;
	while (words[i])
		free(words[i++]);
	free(words);
	return (NULL);
}

char	*ft_strndup(char *s, int slen)
{
	char	*new_s;
	int		i;

	i = 0;
	new_s = (char *)ft_smalloc(slen + 1);
	if (new_s == NULL)
		return (NULL);
	while (s[i] && i < slen)
	{
		new_s[i] = s[i];
		i++;
	}
	new_s[i] = 0;
	return (new_s);
}

static char	**split_string(char *s, char c, char **arr, int slen)
{
	int	i;
	int	j;
	int	idx;

	i = 0;
	idx = 0;
	while (i <= slen)
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[j] != c)
			j++;
		if (i != j)
		{
			arr[idx] = ft_strndup(s + i, j - i);
			idx++;
		}
		i = j;
	}
	arr[idx] = NULL;
	return (arr);
}

char	**ft_parser(char *s, char c)
{
	size_t	size;
	char	**arr;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	size = get_word_count(s, c, slen) + 1;
	arr = (char **)ft_smalloc(size * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	arr = split_string(s, c, arr, slen);
	return (arr);
}
