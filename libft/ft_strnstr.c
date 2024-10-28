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
	size_t	end;

	i = 0;
	end = len - ft_strlen(nn);
	while (hh[i] && i <= end)
	{
		j = 0;
		while (nn[j] && hh[i + j] == nn[j])
			j++;
		if (!nn[j])
			return ((char *)(hh + i));
		i++;
	}
	return (NULL);
}
