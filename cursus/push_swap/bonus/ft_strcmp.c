/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabounou <rabounou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:36:42 by rabounou          #+#    #+#             */
/*   Updated: 2025/01/14 15:36:54 by rabounou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (-1);
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
