/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 22:49:10 by bcorrea-          #+#    #+#             */
/*   Updated: 2023/04/12 22:49:10 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_stop(t_simulation *simulation)
{
	pthread_mutex_lock(&simulation->stop_lock);
	if (simulation->stop == FALSE)
	{
		pthread_mutex_unlock(&simulation->stop_lock);
		return (FALSE);
	}
	pthread_mutex_unlock(&simulation->stop_lock);
	return (TRUE);
}

void	set_stop(t_simulation *simulation, int status)
{
	pthread_mutex_lock(&simulation->stop_lock);
	simulation->stop = status;
	pthread_mutex_unlock(&simulation->stop_lock);
}
