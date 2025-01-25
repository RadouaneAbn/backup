/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabounou <rabounou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:33:18 by rabounou          #+#    #+#             */
/*   Updated: 2025/01/14 15:34:03 by rabounou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

int	get_arg_count(char *s)
{
	int	count;
	int	i;
	int	j;

	i = 0;
	count = 0;
	if (all_args_are_valide_phase1(s) == -1)
		return (-1);
	while (s[i])
	{
		while (s[i] && ft_isspace(s[i]))
			i++;
		j = i;
		while (s[j] && !ft_isspace(s[j]))
			j++;
		if (i != j)
			count++;
		i = j;
	}
	if (count == 0)
		return (-1);
	return (count);
}

int	get_correct_count(int ac, char **av)
{
	int	i;
	int	count;
	int	current_count;

	i = 1;
	count = 0;
	while (i < ac)
	{
		current_count = get_arg_count(av[i++]);
		if (current_count == -1)
			return (-1);
		count += current_count;
	}
	return (count);
}
