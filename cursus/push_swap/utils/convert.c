/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabounou <rabounou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:34:12 by rabounou          #+#    #+#             */
/*   Updated: 2025/01/14 15:34:16 by rabounou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

int	ft_atoi_safe(t_stack *stack, char *s, int size)
{
	long int	n;
	int			sign;
	int			i;

	sign = 0;
	i = 0;
	n = 0;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = 1;
		i++;
	}
	while (s[i] && i < size)
	{
		n = n * 10 + s[i++] - '0';
		if (n > (long)INT_MAX + sign)
			return (-1);
	}
	if (sign)
		n *= -1;
	if (already_in_stack(stack, n))
		return (-1);
	stack->stack[(stack->size)++] = (int)n;
	return (0);
}

int	convert_args_to_int(t_stack *a, char *s)
{
	int	i;
	int	j;
	int	status;

	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == ' ')
			i++;
		j = i;
		while (s[j] && s[j] != ' ')
			j++;
		if (i != j)
		{
			status = ft_atoi_safe(a, s + i, j - i);
			if (status == -1)
				return (-1);
		}
		i = j;
	}
	return (0);
}
