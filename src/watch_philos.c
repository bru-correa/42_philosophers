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
#include <unistd.h>

static int	check_death(t_simulation *simulation, t_philo *philos);
static int	check_meals(t_simulation *simulation, t_philo *philos);

void	watch_philos(t_simulation *simulation, t_philo *philos)
{
	while (check_stop(simulation) == FALSE)
	{
		if (check_death(simulation, philos) == TRUE)
		{
			set_stop(simulation, TRUE);
			break ;
		}
		else if (check_meals(simulation, philos) == TRUE)
			break ;
		usleep(100);
	}
}

static int	check_meals(t_simulation *simulation, t_philo *philos)
{
	unsigned int	i;

	i = 0;
	while (i < simulation->philo_count)
	{
		if (philos[i].meals_count > 0)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static int	check_death(t_simulation *simulation, t_philo *philos)
{
	unsigned int	i;

	i = 0;
	while (i < simulation->philo_count)
	{
		if (get_delta_time(philos->last_meal_time) >= simulation->time_to_die)
		{
			set_stop(simulation, TRUE);
			log_death(philos[i]);
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}
