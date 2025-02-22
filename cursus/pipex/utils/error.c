/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabounou <rabounou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 22:33:52 by rabounou          #+#    #+#             */
/*   Updated: 2025/02/22 22:33:53 by rabounou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/garbage_collector.h"
#include "../includes/utils.h"

void	clean_exit(int exit_code)
{
	free_all();
	exit(exit_code);
}

void	print_usage_error(int type, char *filename)
{
	write(2, "Usage: ", 7);
	write(2, filename, ft_strlen(filename));
	if (type == MANDATORY_PART)
		write(2, " input_file cmd1 cmd2 output_file\n", 34);
	else
	{
		write(2, " input_file cmd1 cmd2 ...[cmdn] output_file\n     : ", 51);
		write(2, filename, ft_strlen(filename));
		write(2, " here_doc LIMITER cmd cmd1 output_file\n", 39);
	}
	exit(1);
}

void	print_error(char *name, char *error)
{
	char	*str;
	int		slen;
	int		i;

	slen = ft_strlen(name) + ft_strlen(error) + 15;
	if (name == NULL || error == NULL)
		clean_exit(1);
	str = (char *)malloc(slen);
	if (str)
	{
		str[0] = 0;
		i = ft_strcat(str, "pipex: ");
		i += ft_strcat(str + i, name);
		i += ft_strcat(str + i, error);
		write(2, str, i);
		free(str);
	}
}

void	print_perror(char *name)
{
	char	*str;

	str = ft_strjoin("pipex: ", name);
	perror(str);
	free(str);
}

void	exit_error(char *name, int error_code, int exit_code)
{
	if (error_code == MALC_EXIT)
		print_error(name, MALC_EM);
	else if (error_code == DIRE_EXIT)
		print_error(name, DIRE_EM);
	else if (error_code == PERM_EXIT)
		print_error(name, PERM_EM);
	else if (error_code == COMD_EXIT)
		print_error(name, COMD_EM);
	clean_exit(exit_code);
}
