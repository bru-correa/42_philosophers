/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watch_philos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:24:43 by bcorrea-          #+#    #+#             */
/*   Updated: 2023/04/12 18:24:43 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

static int	is_everyone_alive(t_simulation *simulation, t_philo *philos);
static int	is_dinner_over(t_simulation *simulation, t_philo *philos);
static int	is_alive(t_philo *philo, t_simulation *simulation);

void	watch_philos(t_simulation *simulation, t_philo *philos)
{
	while (check_stop(simulation) == FALSE)
	{
		if (is_everyone_alive(simulation, philos) == FALSE)
		{
			set_stop(simulation, TRUE);
			break ;
		}
		else if (is_dinner_over(simulation, philos))
			break ;
		usleep(100);
	}
}

static int	is_dinner_over(t_simulation *simulation, t_philo *philos)
{
	unsigned int	i;

	i = 0;
	while (i < simulation->philo_count)
	{
		if (check_ate_all_meals(philos[i]) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static int	is_everyone_alive(t_simulation *simulation, t_philo *philos)
{
	unsigned int	i;

	i = 0;
	while (i < simulation->philo_count)
	{
		if (is_alive(&philos[i], simulation) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static int	is_alive(t_philo *philo, t_simulation *simulation)
{
	pthread_mutex_lock(philo->meal_lock);
	if (get_delta_time(philo->last_meal_time) >= simulation->time_to_die
			&& philo->meals_count != 0)
	{
		log_death(*philo);
		pthread_mutex_unlock(philo->meal_lock);
		return (FALSE);
	}
	pthread_mutex_unlock(philo->meal_lock);
	return (TRUE);
}
