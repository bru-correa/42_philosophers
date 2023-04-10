/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_simulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:20:08 by marvin            #+#    #+#             */
/*   Updated: 2023/04/10 16:00:21 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "philosophers.h"
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

static void	check_arg_count(int argc);
static int	set_meals_count(int argc, char *arg);
static int	set_timer(char *arg, char *arg_name);
static int	set_count(char *arg, char *arg_name);

t_simulation	*create_simulation(int argc, char **argv)
{
	t_simulation	*simulation;

	simulation = malloc(sizeof(t_simulation));
	if (simulation == NULL)
		exit(EXIT_FAILURE);
	check_arg_count(argc);
	simulation->philo_count = set_count(argv[1], "number_of_philosophers");
	simulation->time_to_die = set_timer(argv[2], "time_to_die");
	simulation->time_to_eat = set_timer(argv[3], "time_to_eat");
	simulation->time_to_sleep = set_timer(argv[4], "time_to_sleep");
	simulation->philo_meals_count = set_meals_count(argc, argv[5]);
	simulation->start_time = get_current_time();
	simulation->stop = FALSE;
	pthread_mutex_init(&simulation->print_lock, NULL);
	pthread_mutex_init(&simulation->stop_lock, NULL);
	return (simulation);
}

static void	check_arg_count(int argc)
{
	if (argc < 5)
	{
		ft_putstr_fd("Error\nYou must pass all the necessary arguments\n",
			STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	else if (argc > 6)
	{
		ft_putstr_fd("Error\nToo many arguments\n",
			STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

static int	set_meals_count(int argc, char *arg)
{
	if (argc == 6)
		return (set_count(arg, "number_of_time_each_philosophers_must_eat"));
	return (0);
}

static int	set_timer(char *arg, char *arg_name)
{
	int	count;

	count = ft_atoi(arg);
	if (count < 0)
	{
		ft_putstr_fd("ERROR: ", STDERR_FILENO);
		ft_putstr_fd("Can't have negative numbers in ", STDERR_FILENO);
		ft_putstr_fd(arg_name, STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	return (count);
}

static int	set_count(char *arg, char *arg_name)
{
	int	count;

	count = ft_atoi(arg);
	if (count <= 0)
	{
		ft_putstr_fd("ERROR: ", STDERR_FILENO);
		ft_putstr_fd("The number must be greater than 1 in ", STDERR_FILENO);
		ft_putstr_fd(arg_name, STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	return (count);
}
