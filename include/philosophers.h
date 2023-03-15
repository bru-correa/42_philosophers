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

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include <sys/time.h>

typedef enum u_status
{
	THINKING,
	EATING,
	SLEEPING
}	t_status;

typedef struct s_fork
{
	int				available;
	pthread_mutex_t	lock;
}	t_fork;

typedef struct s_philosopher
{
	pthread_mutex_t	lock;
	t_status		status;
	t_fork			*left_fork;
	t_fork			*right_fork;
}	t_philosopher;

typedef struct s_logger
{
	// last time philosophers ate...
	t_status	*last_states;
}	t_logger;

unsigned int	get_start_time(void);
unsigned int	get_timestamp(unsigned int start_time);

#endif
