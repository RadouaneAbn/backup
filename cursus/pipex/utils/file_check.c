/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabounou <rabounou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 22:34:19 by rabounou          #+#    #+#             */
/*   Updated: 2025/02/22 22:34:21 by rabounou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

int	file_missing_argument(char *filename)
{
	if (ft_strncmp(filename, ".", 2) == 0)
	{
		print_error(filename, FARG_EM);
		return (1);
	}
	return (0);
}

int	file_missing(char *filename)
{
	if (ft_strchr(filename, '/') != NULL && file_exists(filename) == 0)
		print_error(filename, FILE_EM);
	else if (ft_strchr(filename, '/') == NULL)
		print_error(filename, COMD_EM);
	else
		return (0);
	return (1);
}
