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
		return (FAILURE);;
	log_state_change(*philo, THINKING);
	return (SUCCESS);
}

int	philo_get_forks(t_philo *philo)
{
	if (check_stop(philo->simulation) == TRUE)
		return (FAILURE);
	pthread_mutex_lock(philo->next_fork);
	log_fork(*philo);
	if (check_stop(philo->simulation) == TRUE)
	{
		pthread_mutex_unlock(philo->next_fork);
		return (FAILURE);
	}
	if (philo->prev_fork == NULL)
		return (FAILURE);
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

int	philo_eat(t_philo *philo)
{
	log_state_change(*philo, EATING);
	philo->last_meal_time = get_current_time();
	usleep(philo->simulation->time_to_eat * 1000);
	pthread_mutex_unlock(philo->next_fork);
	pthread_mutex_unlock(philo->prev_fork);
	pthread_mutex_lock(&philo->last_meal_lock);
	if (philo->meals_count > 0)
	{
		philo->meals_count--;
	}
	pthread_mutex_unlock(&philo->last_meal_lock);
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
