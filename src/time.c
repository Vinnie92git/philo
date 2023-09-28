/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipalaci <vipalaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:31:14 by vipalaci          #+#    #+#             */
/*   Updated: 2023/09/28 12:31:20 by vipalaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long long	time_mls(void)
{
	struct timeval			tv;

	if (gettimeofday(&tv, NULL) == 0)
		return (((tv.tv_sec) * (unsigned int)1000) + ((tv.tv_usec) / 1000));
	else
		return (0);
}
