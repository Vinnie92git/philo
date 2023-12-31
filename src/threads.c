/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipalaci <vipalaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:31:05 by vipalaci          #+#    #+#             */
/*   Updated: 2023/09/28 12:31:09 by vipalaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start_threads(t_data **data)
{
	int	i;

	i = 0;
	while (i < (*data)->philo_count)
	{
		if (pthread_create(&(*data)->threads[i], NULL, &philosopher,
				&(*data)->philos[i]) != 0)
		{
			printf("Could not create a thread.\n");
			return (0);
		}
		usleep(1);
		i++;
	}
	return (1);
}

int	stop_threads(t_data **data)
{
	int	i;

	i = 0;
	while (i < (*data)->philo_count)
	{
		if (pthread_join((*data)->threads[i], NULL) != 0)
		{
			printf("Error while joining a thread %i.\n", i);
			return (0);
		}
		i++;
	}
	return (1);
}
