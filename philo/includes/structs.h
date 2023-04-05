/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:49:04 by victofer          #+#    #+#             */
/*   Updated: 2023/04/05 12:24:15 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include<pthread.h>

//	M A C R O S
# define TRUE 1
# define FALSE 0
# define INPUT_ERROR "BAD INPUT"
# define MALLOC_ERROR "MEMORY ERROR"
# define THREAD_ERROR "THREAD ERROR."
# define MUTEX_ERROR "MUTEX ERROR"
# define GENERIC_ERROR "SOMETHING WERE WRONG"

// -------------- C O L O R S ------------------

# define R	"\x1B[31m"
# define G	"\x1B[32m"
# define BG	"\x1B[92m"
# define Y	"\x1B[33m"
# define B	"\x1B[36m"	
# define W	"\x1B[37m"
# define BY	"\x1B[93m"
# define BM	"\x1B[95m"

//   S T R U C T U R E S

typedef struct s_philo	t_philo;

typedef struct s_table
{
	time_t			time_start;
	int				nb_philo;
	pthread_t		dead_checker;
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
	pthread_t		thid;
	int				id;
	int				times_ate;
	int				*forks;
	pthread_mutex_t	meal_lock;
	time_t			last_meal;
	t_table			*table;
}	t_philo;

#endif