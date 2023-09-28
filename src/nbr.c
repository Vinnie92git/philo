/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipalaci <vipalaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:30:23 by vipalaci          #+#    #+#             */
/*   Updated: 2023/09/28 12:30:29 by vipalaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long	result;

	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r'
		|| *str == '\v' || *str == '\f')
		str++;
	if (*str == '-')
		return (-1);
	if (*str == '+')
		str++;
	result = 0;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (-1);
		result = result * 10 + *str - '0';
		if (result > INT_MAX || result < 0)
			return (-1);
		str++;
	}
	return ((int)result);
}
