/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 23:23:14 by bcorrea-          #+#    #+#             */
/*   Updated: 2023/03/15 00:48:03 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "libft.h"
#include <sys/time.h>

static unsigned int	get_time_in_ms(void);

unsigned int	get_current_time(void)
{
	return (get_time_in_ms());
}

unsigned int	get_delta_time(unsigned int start_time)
{
	unsigned int	time_in_ms;

	time_in_ms = get_time_in_ms();
	return (time_in_ms - start_time);
}

static unsigned int	get_time_in_ms(void)
{
	struct timeval	tv;
	unsigned int	time_in_usec;
	unsigned int	time_in_ms;

	if (gettimeofday(&tv, NULL) == -1)
	{
		ft_putstr_fd("ERROR\nCan't get timestamp\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	time_in_usec = (tv.tv_sec * 1000000) + tv.tv_usec;
	time_in_ms = time_in_usec / 1000;
	return (time_in_ms);
}
