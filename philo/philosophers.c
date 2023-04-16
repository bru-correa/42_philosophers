/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 17:32:40 by bcorrea-          #+#    #+#             */
/*   Updated: 2023/03/15 00:51:24 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>
#include <stdlib.h>

static void	destroy_philos(t_philo *philos)
{
	unsigned int	i;

	i = 0;
	while (i < philos->simulation->philo_count)
	{
		free(philos[i].meal_lock);
		i++;
	}
	free(philos);
}

int	main(int argc, char **argv)
{
	t_simulation	*simulation;
	pthread_mutex_t	**forks;
	t_philo			*philos;

	simulation = create_simulation(argc, argv);
	forks = create_forks(simulation->philo_count);
	philos = create_philos(simulation, forks);
	run_simulation(simulation, philos);
	destroy_forks(forks, simulation->philo_count);
	destroy_philos(philos);
	destroy_simulation(simulation);
	return (0);
}
