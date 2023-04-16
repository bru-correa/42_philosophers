/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meals.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 19:14:06 by bcorrea-          #+#    #+#             */
/*   Updated: 2023/04/15 19:14:06 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

int	check_ate_all_meals(t_philo philo)
{
	pthread_mutex_lock(philo.meal_lock);
	if (philo.meals_count == 0)
	{
		pthread_mutex_unlock(philo.meal_lock);
		return (TRUE);
	}
	pthread_mutex_unlock(philo.meal_lock);
	return (FALSE);
}

void	eat_meal(t_philo *philo)
{
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal_time = get_current_time();
	if (philo->meals_count > 0)
		philo->meals_count--;
	pthread_mutex_unlock(philo->meal_lock);
	usleep(philo->simulation->time_to_eat * 1000);
}
