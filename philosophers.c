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
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	*routine()
{
	printf("Hello philo\n");
	usleep(1000);
	return  (NULL);
}

pthread_t	*create_threads(int count)
{
	pthread_t	*threads;
	int			i;

	threads = malloc(sizeof(pthread_t) * count);
	i = 0;
	while (i < count)
	{
		pthread_create(&threads[i], NULL, &routine, NULL);
		i++;
	}
	return (threads);
}

int	main(int argc, char **argv)
{
	t_simulation	*simulation;
	pthread_mutex_t	*forks;
	t_philo			*philos;

	simulation = create_simulation(argc, argv);
	forks = create_forks(simulation->philo_count);
	philos = create_philos(simulation, forks);
	// TODO: run simulation
	destroy_forks(forks, simulation->philo_count);
	destroy_simulation(simulation);
	free(philos);
	return (0);
}
