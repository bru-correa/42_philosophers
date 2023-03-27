/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 17:31:40 by bcorrea-          #+#    #+#             */
/*   Updated: 2023/03/15 00:48:15 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

/********** INCLUDES **********/

# include <pthread.h>
// # include <stdlib.h>
// # include <unistd.h>
// # include "libft.h"
// # include <sys/time.h>

/********** MACROS **********/

# define FAILURE 0
# define SUCCESS 1

/********** ENUMS **********/

typedef enum u_status
{
	THINKING,
	EATING,
	SLEEPING
}	t_status;

/********** STRUCTS **********/

typedef struct s_fork
{
	int				available;
	pthread_mutex_t	lock;
}	t_fork;

typedef struct s_philosopher
{
	unsigned int	id; // NOTE: Optional
	pthread_mutex_t	status_lock;
	t_status		status;
	t_fork			*left_fork;
	t_fork			*right_fork;
}	t_philosopher;

typedef struct s_logger
{
	// last time philosophers ate...
	t_status	*last_states;
}	t_logger;

typedef struct s_simulation
{
	unsigned int	philo_count;
	unsigned int	philo_meals_count;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	int				start_time;
}	t_simulation;

/********** PROTOTYPES **********/

/**
 * Get the number of seconds since the Epoch
 */
unsigned int	get_start_time(void);

/**
 * Get how many time in ms have passed since the program started
 */
unsigned int	get_timestamp(unsigned int start_time);

/**
 * Check if `argv` arguments are valid and return the simulation setup.
 * In case of error, the program will exit with status code of 1
 */
t_simulation	setup_simulation(int argc, char **argv);
#endif
