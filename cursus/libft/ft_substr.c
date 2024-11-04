/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabounou <rabounou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 21:44:04 by rabounou          #+#    #+#             */
/*   Updated: 2024/11/04 11:57:53 by rabounou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
char    *ft_substr(const char *s, unsigned int start, size_t len)
{
    char    *str;
    size_t    i;
    size_t    slen;
	size_t	rlen;

    if (!s)
        return (NULL);
    slen = ft_strlen(s);
    if (start > slen)
        return (ft_strdup(""));
    if (start + len < slen)
        rlen = len;
    else
        rlen = slen - start ;
	str = malloc(sizeof(char) * (rlen + 1));
    if (!str)
        return (NULL);
    i = 0;
    while (i < rlen)
        str[i++] = s[start++];
    str[i] = '\0';
    return (str);
}
