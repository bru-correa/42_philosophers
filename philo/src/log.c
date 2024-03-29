/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:30:01 by bcorrea-          #+#    #+#             */
/*   Updated: 2023/04/12 20:30:01 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>
#include <stdio.h>

void	log_state_change(t_philo philo, char *state)
{
	unsigned int	timestamp;

	pthread_mutex_lock(&philo.simulation->print_lock);
	timestamp = get_delta_time(philo.simulation->start_time);
	printf("%u %d is %s\n", timestamp, philo.id, state);
	pthread_mutex_unlock(&philo.simulation->print_lock);
}

void	log_fork(t_philo philo)
{
	unsigned int	timestamp;

	pthread_mutex_lock(&philo.simulation->print_lock);
	timestamp = get_delta_time(philo.simulation->start_time);
	printf("%u %d has taken a fork\n", timestamp, philo.id);
	pthread_mutex_unlock(&philo.simulation->print_lock);
}

void	log_death(t_philo philo)
{
	unsigned int	timestamp;

	pthread_mutex_lock(&philo.simulation->print_lock);
	timestamp = get_delta_time(philo.simulation->start_time);
	printf("%u %d died\n", timestamp, philo.id);
	pthread_mutex_unlock(&philo.simulation->print_lock);
}

void	log_meal_end(t_philo philo)
{
	unsigned int	timestamp;

	pthread_mutex_lock(&philo.simulation->print_lock);
	timestamp = get_delta_time(philo.simulation->start_time);
	printf("%u %d has finished eating\n", timestamp, philo.id);
	pthread_mutex_unlock(&philo.simulation->print_lock);
}
