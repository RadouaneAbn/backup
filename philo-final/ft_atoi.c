/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabounou <rabounou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 02:50:25 by rabounou          #+#    #+#             */
/*   Updated: 2025/07/28 02:50:51 by rabounou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

bool	ft_atoi(const char *str, int *result)
{
	long int	n;
	int			sign;
	int			i;

	sign = 0;
	i = 0;
	n = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = 1;
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		n = n * 10 + str[i++] - '0';
		if (n > (long)INT_MAX + sign)
			return (false);
	}
	if (sign)
		n *= -1;
	*result = (int)n;
	return (true);
}
