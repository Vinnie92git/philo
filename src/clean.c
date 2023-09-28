/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipalaci <vipalaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:28:56 by vipalaci          #+#    #+#             */
/*   Updated: 2023/09/28 12:29:00 by vipalaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clean(t_data **data)
{
	int	i;

	if (!*data)
		return ;
	i = (*data)->philo_count;
	pthread_mutex_destroy(&(*data)->lock);
	pthread_mutex_destroy(&(*data)->print_lock);
	pthread_mutex_destroy(&(*data)->eat_lock);
	while (i > 0)
	{
		if ((*data)->philos)
			pthread_mutex_destroy(&(*data)->philos[i - 1].lock);
		if ((*data)->forks)
			pthread_mutex_destroy(&(*data)->forks[i - 1]);
		i--;
	}
	if ((*data)->philos)
		free((*data)->philos);
	if ((*data)->forks)
		free((*data)->forks);
	if ((*data)->threads)
		free((*data)->threads);
	if (*data)
		free(*data);
}
