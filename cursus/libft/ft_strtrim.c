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

	if (!s1[0])
		return (0);
	i = 0;
	slen = ft_strlen(s1);
	if (slen > 0)
		slen--;
	while (s1[i] && char_in_charset(s1[i], set))
		i++;
	if (i >= slen)
		return (slen);
	while (s1[slen] && char_in_charset(s1[slen], set))
		slen--;
	return (slen - i + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	char	*new_str;
	size_t	new_size;

	if (s1 == NULL)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	new_size = get_final_len(s1, set) + 1;
	new_str = (char *) malloc((new_size) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (s1[i] && char_in_charset(s1[i], set))
		i++;
	ft_strlcpy(new_str, s1 + i, new_size);
	return (new_str);
}
