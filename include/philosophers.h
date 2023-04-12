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

/********** MACROS **********/

# define FAILURE 0
# define SUCCESS 1

# ifndef TRUE
#  define TRUE 1
# endif

# ifndef FALSE
#  define FALSE 0
# endif

/********** ENUMS **********/

typedef enum u_status
{
	THINKING,
	EATING,
	SLEEPING
}	t_status;

/********** STRUCTS **********/

typedef struct s_simulation
{
	unsigned int	philo_count;
	unsigned int	philo_meals_count;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	start_time;
	int				stop;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	stop_lock;
}	t_simulation;

typedef struct s_philo
{
	unsigned int	id;
	unsigned int	meals_count;
	unsigned int	last_meal_time;
	pthread_mutex_t	last_meal_lock;
	pthread_mutex_t	next_fork;
	pthread_mutex_t	prev_fork;
	t_simulation	*simulation;
}	t_philo;

/********** PROTOTYPES **********/

/**
 * Get the current time in milliseconds
 */
unsigned int	get_current_time(void);

/**
 * Get how many time in milliseconds have passed since `start_time`
 */
unsigned int	get_delta_time(unsigned int start_time);

/**
 * Check if `argv` arguments are valid and return the simulation setup.
 * In case of error, the program will exit with status code of 1
 */
t_simulation	*create_simulation(int argc, char **argv);

void			destroy_simulation(t_simulation *simulation);

pthread_mutex_t	*create_forks(int count);

void			destroy_forks(pthread_mutex_t *forks, int count);

t_philo			*create_philos(t_simulation *simulation,
					pthread_mutex_t *forks);

void			run_simulation(t_simulation *simulation, t_philo *philos);

void			*routine(t_philo *philo);

#endif
