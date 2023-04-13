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

void	*routine(t_philo *philo)
{
	if (philo->id % 2 == 0)
		usleep(1000);
	while (philo->meals_count != 0)
	{
		if (check_stop(philo->simulation) == TRUE)
			return (NULL);
		log_state_change(*philo, THINKING);
		log_fork(*philo);
		log_state_change(*philo, EATING);
		usleep(philo->simulation->time_to_eat * 1000);
	}
	return (NULL);
}
