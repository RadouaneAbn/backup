/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabounou <rabounou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:22:30 by rabounou          #+#    #+#             */
/*   Updated: 2024/10/22 17:59:24 by rabounou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	idx;

	i = 0;
	idx = -1;
	while (s[i])
	{
		if (s[i] == c)
			idx = i;
		i++;
	}
	if (!s[i] && c == 0)
		return ((char *)(s + i));
	if (idx == -1)
		return (NULL);
	return ((char *)(s + idx));
}
