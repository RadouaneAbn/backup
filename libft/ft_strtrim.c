/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabounou <rabounou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:09:25 by rabounou          #+#    #+#             */
/*   Updated: 2024/10/25 19:55:23 by rabounou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	char_in_charset(char c, char const *charset)
{
	if (charset == NULL)
		return (0);
	while (*charset)
	{
		if (*charset == c)
			return (1);
		charset++;
	}
	return (0);
}

static size_t	get_final_len(char const *s1, char const *set)
{
	size_t	slen;
	size_t	i;

	i = 0;
	slen = 0;
	while (s1[i])
	{
		if (!char_in_charset(s1[i], set))
			slen++;
		i++;
	}
	return (slen);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*new_str;
	size_t	new_size;

	if (s1 == NULL)
		return (NULL);
	new_size = get_final_len(s1, set);
	new_str = (char *) malloc((new_size + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		if (!char_in_charset(s1[i], set))
			new_str[j++] = s1[i];
		i++;
	}
	new_str[j] = 0;
	return (new_str);
}
