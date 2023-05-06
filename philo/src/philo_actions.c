/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 23:41:31 by bcorrea-          #+#    #+#             */
/*   Updated: 2023/04/12 23:41:31 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

int	philo_think(t_philo *philo)
{
	if (check_stop(philo->simulation) == TRUE)
		return (FAILURE);
	log_state_change(*philo, THINKING);
	return (SUCCESS);
}

int	philo_get_forks(t_philo *philo)
{
	if (check_stop(philo->simulation) == TRUE)
		return (FAILURE);
	pthread_mutex_lock(philo->next_fork);
	if (check_stop(philo->simulation) == TRUE || philo->prev_fork == NULL)
	{
		pthread_mutex_unlock(philo->next_fork);
		return (FAILURE);
	}
	log_fork(*philo);
	pthread_mutex_lock(philo->prev_fork);
	if (check_stop(philo->simulation) == TRUE)
	{
		pthread_mutex_unlock(philo->next_fork);
		pthread_mutex_unlock(philo->prev_fork);
		return (FAILURE);
	}
	log_fork(*philo);
	return (SUCCESS);
}

void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->next_fork);
	pthread_mutex_unlock(philo->prev_fork);
}

int	philo_eat(t_philo *philo)
{
	log_state_change(*philo, EATING);
	eat_meal(philo);
	return (SUCCESS);
}

int	philo_sleep(t_philo *philo)
{
	if (check_stop(philo->simulation) == TRUE)
		return (FAILURE);
	log_state_change(*philo, SLEEPING);
	usleep(philo->simulation->time_to_sleep * 1000);
	return (SUCCESS);
}
