/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabounou <rabounou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:13:42 by rabounou          #+#    #+#             */
/*   Updated: 2025/01/14 15:13:44 by rabounou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r')
		return (1);
	return (0);
}

int	ft_isnum(int c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	return (0);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
