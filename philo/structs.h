/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:49:04 by victofer          #+#    #+#             */
/*   Updated: 2023/03/29 10:18:25 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <pthread.h>
# define TRUE 1
# define FALSE 0
# define NUM_ARGS_ERROR "Incorrect number of arguments."
# define ARGS_FORMAT_ERROR "Bad format of one or more arguments (digits)."
# define MALLOC_ERROR "Fail to alllocates memory."
# define PHILO_ERROR "Fail to create philosophers."
# define MUTEX_ERROR "Fail to create mutexes."
//   S T R U C T U R E S

typedef struct s_philo	t_philo;

typedef struct s_table
{
	int				time_start;
	int				nb_philo;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	int				times_x_eat;
	int				simulation_stop;
	pthread_mutex_t	sim_stop_lock;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	*fork_locks;
	t_philo			**philos;
}	t_table;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				times_ate;
	int				*forks;
	pthread_mutex_t	meal_lock;
	time_t			last_meal;
	t_table			*table;
}	t_philo;

typedef enum e_status
{
	DEAD = 0,
	EATING = 0,
	SLEEPING = 0,
	THINKING = 0,
	FORK_1 = 0,
	FORK_2 = 0
}	t_status;

#endif