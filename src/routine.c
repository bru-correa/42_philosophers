/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:09:52 by bcorrea-          #+#    #+#             */
/*   Updated: 2023/04/12 18:09:52 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

// WARNING: Data race while checking meals count
void	*routine(t_philo *philo)
{
	if (philo->id % 2 == 0)
		usleep(1000);
	while (philo->meals_count != 0)
	{
		if (philo_think(philo) == FAILURE)
			break;
		if (philo_get_forks(philo) == FAILURE)
			break;
		if (philo_eat(philo) == FAILURE)
			break ;
		if (philo_sleep(philo) == FAILURE)
			break ;
	}
	return (NULL);
}
