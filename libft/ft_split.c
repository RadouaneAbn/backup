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

#include "libft.h"

static size_t	get_word_count(char const *s, char c)
{
	size_t	wcount;
	int		word_found;

	wcount = 0;
	word_found = 0;
	while (*s)
	{
		if (word_found && *s == c)
		{
			word_found = 0;
			wcount++;
		}
		if (!word_found && *s != c)
			word_found = 1;
		s++;
	}
	if (word_found)
		wcount++;
	return (wcount);
}

static void	*free_all(char **arr, size_t idx)
{
	while (idx > 0)
		free(arr[--idx]);
	free(arr);
	return (NULL);
}

static char	*ft_strndup(char const *s, size_t n, int *word_found)
{
	char	*new_str;
	size_t	i;

	*word_found = 0;
	new_str = (char *) malloc((n + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		new_str[i] = s[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

static char	**split_string(char const *s, char c, char **arr)
{
	int		word_found;
	size_t	ij[2];
	size_t	idx;

	word_found = 0;
	ij[0] = -1;
	idx = 0;
	while (s[++ij[0]])
	{
		if (word_found && s[ij[0]] == c)
		{
			arr[idx++] = ft_strndup(s + ij[1], ij[0] - ij[1], &word_found);
			if (arr[idx - 1] == NULL)
				return (free_all(arr, idx));
		}
		if (!word_found && s[ij[0]] != c)
		{
			word_found = 1;
			ij[1] = ij[0];
		}
	}
	if (word_found)
		arr[idx++] = ft_strndup(s + ij[1], ij[0] - ij[1], &word_found);
	arr[idx] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	size_t	size;
	char	**arr;

	size = get_word_count(s, c) + 1;
	arr = (char **) malloc(size * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	arr = split_string(s, c, arr);
	return (arr);
}
