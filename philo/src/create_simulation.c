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

#include "philosophers.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void	check_arg_count(int argc);
static int	set_meals_count(int argc, char *arg, t_simulation *simulation);
static int	set_timer(char *arg, char *arg_name, t_simulation *simulation);
static int	set_count(char *arg, char *arg_name, t_simulation *simulation);

t_simulation	*create_simulation(int argc, char **argv)
{
	t_simulation	*simulation;

	check_arg_count(argc);
	simulation = malloc(sizeof(t_simulation));
	if (simulation == NULL)
		exit(EXIT_FAILURE);
	simulation->philo_count = set_count(argv[1], "number_of_philosophers",
			simulation);
	simulation->time_to_die = set_timer(argv[2], "time_to_die", simulation);
	simulation->time_to_eat = set_timer(argv[3], "time_to_eat", simulation);
	simulation->time_to_sleep = set_timer(argv[4], "time_to_sleep", simulation);
	simulation->philo_meals_count = set_meals_count(argc, argv[5], simulation);
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
		printf("Error\nYou must pass all the necessary arguments\n");
		exit(EXIT_FAILURE);
	}
	else if (argc > 6)
	{
		printf("Error\nToo many arguments\n");
		exit(EXIT_FAILURE);
	}
}

// Return -1 in case of unlimited meals
static int	set_meals_count(int argc, char *arg, t_simulation *simulation)
{
	if (argc == 6)
	{
		if (is_number(arg) == FALSE)
		{
			printf("ERROR: You need to pass a valid number\n");
			free(simulation);
			exit(EXIT_FAILURE);
		}
		return (set_count(arg, "number_of_time_each_philosophers_must_eat",
				simulation));
	}
	return (-1);
}

static int	set_timer(char *arg, char *arg_name, t_simulation *simulation)
{
	int	count;

	if (is_number(arg) == FALSE)
	{
		printf("ERROR: You need to pass a valid number\n");
		free(simulation);
		exit(EXIT_FAILURE);
	}
	count = ft_atoi(arg);
	if (count < 0)
	{
		printf("ERRROR: Can't have negative numbers in %s\n", arg_name);
		free(simulation);
		exit(EXIT_FAILURE);
	}
	return (count);
}

static int	set_count(char *arg, char *arg_name, t_simulation *simulation)
{
	int	count;

	if (is_number(arg) == FALSE)
	{
		printf("ERROR: You need to pass a valid number\n");
		free(simulation);
		exit(EXIT_FAILURE);
	}
	count = ft_atoi(arg);
	if (count <= 0)
	{
		printf("ERROR: The number must be greater than 1 in %s\n", arg_name);
		free(simulation);
		exit(EXIT_FAILURE);
	}
	return (count);
}
