/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_simulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:25:02 by bcorrea-          #+#    #+#             */
/*   Updated: 2023/04/10 15:25:02 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>
#include <stdlib.h>

void	destroy_simulation(t_simulation *simulation)
{
	pthread_mutex_destroy(&simulation->print_lock);
	pthread_mutex_destroy(&simulation->stop_lock);
	free(simulation);
}
