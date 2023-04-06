/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <bruuh.cor@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:41:52 by marvin            #+#    #+#             */
/*   Updated: 2023/04/06 16:59:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdlib.h>

static t_status	*init_status(int philo_count);
static int		*init_stop(void);

t_manager	create_manager(int philo_count)
{
	t_manager	manager;

	manager.previous_status = init_status(philo_count);
	manager.stop = init_stop();
	return (manager);
}

static t_status	*init_status(int philo_count)
{
	t_status	*status;
	int			i;
	
	status = malloc(sizeof(t_status) * philo_count);
	if (status == NULL)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < philo_count)
	{
		status[i] = THINKING;
		i++;
	}
	return (status);
}

static int	*init_stop(void)
{
	int	*stop;
	
	stop = malloc(sizeof(int));
	if (stop == NULL)
		exit(EXIT_FAILURE);
	stop = FALSE;
	return (stop);
}
