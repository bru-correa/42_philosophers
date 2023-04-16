/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:22:18 by bcorrea-          #+#    #+#             */
/*   Updated: 2023/04/10 17:22:18 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

static pthread_t	*start_threads(int count, t_philo *philos);
static void			destroy_threads(pthread_t *threads, int count);

void	run_simulation(t_simulation *simulation, t_philo *philos)
{
	pthread_t	*threads;

	threads = start_threads(simulation->philo_count, philos);
	if (threads == NULL)
		return ;
	watch_philos(simulation, philos);
	destroy_threads(threads, simulation->philo_count);
}

static pthread_t	*start_threads(int count, t_philo *philos)
{
	int			i;
	pthread_t	*threads;

	threads = malloc(sizeof(pthread_t) * count);
	if (threads == NULL)
		return (NULL);
	i = 0;
	while (i < count)
	{
		pthread_create(&threads[i], NULL, (void *)&routine, &philos[i]);
		i++;
	}
	return (threads);
}

static void	destroy_threads(pthread_t *threads, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	free(threads);
}
