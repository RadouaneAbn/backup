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

static size_t	get_word_count(char const *s, char c, size_t slen)
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

static char	**split_string(char const *s, char c, char **arr, size_t slen)
{
	size_t	i;
	size_t	j;
	size_t	idx;
	int		word_found;

	i = 0;
	word_found = 0;
	idx = 0;
	while (i <= slen)
	{
		if (!word_found && (s[i] != c && s[i] != '\0'))
		{
			j = i;
			word_found = 1;
		}
		else if (word_found && (s[i] == c || s[i] == '\0'))
		{
			arr[idx] = ft_strndup(s + j, i - j, &word_found);
			if (arr[idx++] == NULL)
				return (free_all(arr, idx));
		}
		i++;
	}
	arr[idx] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	size_t	size;
	char	**arr;
	size_t	slen;

	slen = ft_strlen(s);
	size = get_word_count(s, c, slen) + 1;
	arr = (char **) malloc(size * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	arr = split_string(s, c, arr, slen);
	return (arr);
}
