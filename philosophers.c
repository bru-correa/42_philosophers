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

int	main(void)
{
	int	timestamp;
	int	start_time;
	// get start time
	// create forks
	// create philosophers
	start_time = get_start_time();
	timestamp = get_timestamp(start_time);
	ft_printf("Timestamp: %d\n", timestamp);
	usleep(100000);
	timestamp = get_timestamp(start_time);
	ft_printf("Timestamp: %d\n", timestamp);
	timestamp = get_timestamp(start_time);
	ft_printf("Timestamp: %d\n", timestamp);
	return (0);
}
