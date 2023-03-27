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

int	main(int argc, char **argv)
{
	t_simulation	simulation;

	simulation = setup_simulation(argc, argv);
	(void)simulation; //HACK: Provisory
	// create mutexes
	// create philos
	return (0);
}
