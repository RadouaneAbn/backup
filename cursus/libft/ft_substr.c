/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabounou <rabounou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 21:44:04 by rabounou          #+#    #+#             */
/*   Updated: 2024/10/25 14:41:27 by rabounou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	size_t	real_len;
	size_t	i;
	char	*sub_string;

	slen = ft_strlen(s);
	real_len = len;
	if (start > slen)
		real_len = 0;
	else if (start + len > slen)
		real_len = slen - start;
	sub_string = (char *) malloc((real_len + 1) * sizeof(char));
	if (sub_string == NULL)
		return (NULL);
	i = 0;
	while (i < real_len)
	{
		sub_string[i] = s[i + start];
		i++;
	}
	sub_string[i] = '\0';
	return (sub_string);
}
