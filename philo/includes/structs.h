/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:49:04 by victofer          #+#    #+#             */
/*   Updated: 2023/04/03 12:57:08 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <pthread.h>

//	M A C R O S
# define TRUE 1
# define FALSE 0
# define INPUT_ERROR "BAD INPUT"
# define MALLOC_ERROR "MEMORY ERROR"
# define THREAD_ERROR "THREAD ERROR."
# define MUTEX_ERROR "MUTEX ERROR"
# define GENERIC_ERROR "SOMETHING WERE WRONG"

//   S T R U C T U R E S

typedef struct s_philo	t_philo;

typedef struct s_table
{
	time_t			time_start;
	int				nb_philo;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	int				times_x_eat;
	int				simulation_stop;
	pthread_t		dead_checker;
	pthread_mutex_t	sim_stop_lock;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	*fork_locks;
	t_philo			**philos;
}	t_table;

typedef struct s_philo
{
	pthread_t		thid;
	int				id;
	int				times_ate;
	int				*forks;
	pthread_mutex_t	meal_lock;
	time_t			last_meal;
	t_table			*table;
}	t_philo;

#endif