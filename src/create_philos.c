/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:10:51 by marvin            #+#    #+#             */
/*   Updated: 2023/04/10 16:09:04 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>
#include <stdlib.h>

static t_philo	setup_philo(
					t_simulation *simulation,
					pthread_mutex_t **forks,
					unsigned int index);

t_philo	*create_philos(t_simulation *simulation, pthread_mutex_t **forks)
{
	t_philo			*philos;
	unsigned int	i;

	philos = malloc(sizeof(t_philo) * simulation->philo_count);
	if (philos == NULL)
		return (NULL);
	i = 0;
	while (i < simulation->philo_count)
	{
		philos[i] = setup_philo(simulation, forks, i);
		i++;
	}
	return (philos);
}

static t_philo	setup_philo(
					t_simulation *simulation,
					pthread_mutex_t **forks,
					unsigned int index)
{
	t_philo	philo;

	philo.id = index + 1;
	philo.meals_count = simulation->philo_meals_count;
	philo.last_meal_time = simulation->start_time;
	pthread_mutex_init(&philo.last_meal_lock, NULL);
	if (index == 0)
	{
		philo.next_fork = forks[0];
		if (simulation->philo_count == 1)
			philo.prev_fork = NULL;
		else
			philo.prev_fork = forks[simulation->philo_count - 1];
	}
	else
	{
		philo.next_fork = forks[index];
		philo.prev_fork = forks[index - 1];
	}
	philo.simulation = simulation;
	return (philo);
}
