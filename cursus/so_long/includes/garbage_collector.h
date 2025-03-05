/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabounou <rabounou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 22:32:30 by rabounou          #+#    #+#             */
/*   Updated: 2025/02/22 22:37:37 by rabounou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARBAGE_COLLECTOR_H
# define GARBAGE_COLLECTOR_H

# include "../includes/defs.h"
# include "../libft/libft.h"

void	appendlist_to_gbcollector(t_list *node);
void	free_all(void);
// void	free_ptr(void *addr);
void	save_ptr(void *data);
void	*ft_smalloc(int size);

#endif
