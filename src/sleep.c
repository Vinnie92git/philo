/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipalaci <vipalaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:30:58 by vipalaci          #+#    #+#             */
/*   Updated: 2023/09/28 12:31:02 by vipalaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	keep_looping_data(t_data **data)
{
	pthread_mutex_lock(&(*data)->lock);
	if (!(*data)->death)
	{
		pthread_mutex_unlock(&(*data)->lock);
		return (1);
	}
	pthread_mutex_unlock(&(*data)->lock);
	return (0);
}

static int	keep_looping_philo(t_philo **philo, t_data **data)
{
	if (philo && *philo)
	{
		pthread_mutex_lock(&(*philo)->lock);
		if (((*philo)->time_since_last_meal
				+ (*data)->time_to_die) < time_mls())
		{
			pthread_mutex_lock(&(*data)->lock);
			(*data)->death = 1;
			pthread_mutex_unlock(&(*data)->lock);
			pthread_mutex_unlock(&(*philo)->lock);
			return (0);
		}
		pthread_mutex_unlock(&(*philo)->lock);
	}
	return (1);
}

int	ft_usleep(unsigned long long time, t_data **data, t_philo **philo)
{
	unsigned long long	start;

	start = time_mls();
	while (keep_looping_data(data))
	{
		if (philo && *philo && !keep_looping_philo(philo, data))
			return (0);
		if (time_mls() - start >= time)
			break ;
		usleep(500);
	}
	return (1);
}
