/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabounou <rabounou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:49:08 by rabounou          #+#    #+#             */
/*   Updated: 2024/10/24 20:24:14 by rabounou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hh, const char *nn, size_t len)
{
	size_t	i;
	size_t	j;

	if ((!hh[0] && !nn[0]) || !nn[0])
		return ((char *)hh);
	i = 0;
	while (hh[i] && i < len)
	{
		j = 0;
		while (nn[j] && hh[i + j] == nn[j] && i + j < len)
			j++;
		if (!nn[j])
			return ((char *)(hh + i));
		i++;
	}
	return (NULL);
}
