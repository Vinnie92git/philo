/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipalaci <vipalaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:30:00 by vipalaci          #+#    #+#             */
/*   Updated: 2023/09/28 12:30:04 by vipalaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_data	*data;

	data = NULL;
	if (invalid_input(argc, argv))
		return (1);
	else if (!init(&data, argv, argc))
	{
		clean(&data);
		return (1);
	}
	dine(&data);
	return (0);
}
