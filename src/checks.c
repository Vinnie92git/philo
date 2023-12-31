/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipalaci <vipalaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:28:47 by vipalaci          #+#    #+#             */
/*   Updated: 2023/09/28 12:28:52 by vipalaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_ate_enough(t_data **data, int i)
{
	pthread_mutex_lock(&(*data)->philos[i].lock);
	if ((*data)->philos[i].full)
	{
		pthread_mutex_unlock(&(*data)->philos[i].lock);
		return (0);
	}
	if ((*data)->philos[i].meals_to_eat == 0)
	{
		(*data)->philos[i].full = 1;
		pthread_mutex_unlock(&(*data)->philos[i].lock);
		return (1);
	}
	pthread_mutex_unlock(&(*data)->philos[i].lock);
	return (0);
}

int	starved(t_data **data, int i)
{
	pthread_mutex_lock(&(*data)->philos[i].lock);
	if (((*data)->meals_to_eat_per_philo == -1
			|| (*data)->philos[i].meals_to_eat > 0)
		&& !(*data)->philos[i].eating
		&& (((*data)->philos[i].time_since_last_meal != 0
				&& (*data)->philos[i].time_since_last_meal
				+ (*data)->time_to_die <= time_mls())
			|| ((*data)->philo_count == 1
				&& (time_mls() - (*data)->start_time)
				> (*data)->time_to_die)))
	{
		pthread_mutex_unlock(&(*data)->philos[i].lock);
		return (1);
	}
	pthread_mutex_unlock(&(*data)->philos[i].lock);
	return (0);
}
