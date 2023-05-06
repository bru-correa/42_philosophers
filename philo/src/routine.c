/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:09:52 by bcorrea-          #+#    #+#             */
/*   Updated: 2023/04/16 07:38:53 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void	*routine(t_philo *philo)
{
	if (philo->id % 2 == 0)
		usleep(1000);
	while (philo->meals_count != 0)
	{
		if (philo_think(philo) == FAILURE)
			break ;
		if (philo_get_forks(philo) == FAILURE)
			break ;
		if (philo_eat(philo) == FAILURE)
			break ;
		release_forks(philo);
		if (philo_sleep(philo) == FAILURE)
			break ;
	}
	if (philo->meals_count == 0) {
		log_meal_end(*philo);
	}
	return (NULL);
}
