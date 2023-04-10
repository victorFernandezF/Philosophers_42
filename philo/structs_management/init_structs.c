/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:39:40 by victofer          #+#    #+#             */
/*   Updated: 2023/04/10 10:45:07 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static pthread_mutex_t	*init_forks(t_rules *rules)
{
	pthread_mutex_t	*forks;
	int				i;

	i = 0;
	forks = malloc(sizeof(pthread_mutex_t) * rules->nb_philo);
	if (!forks)
	{
		print_error_msg(MALLOC_ERROR, "fail allocating forks", 0);
		return (0);
	}
	while (i < rules->nb_philo)
	{
		if (pthread_mutex_init(&forks[i], 0) != 0)
		{
			print_error_msg(MUTEX_ERROR, "fail to create mutex: forks", 0);
			free(forks);
			return (NULL);
		}
		i++;
	}
	return (forks);
}

/* 
 * asign_forks
 * ----------------------------
 *	Asign two forks to each philosopher.
 *	The objective of the function is to avoid deathlocks
 *	(situations in which every philosopher take a fork but any of them
 *	is able to eat so everyone die like stupids.)
 * 
 *	philos: struct with each philosopher datas.
 */
void	asign_forks(t_philo *philos)
{
	philos->forks[0] = philos->id;
	philos->forks[1] = (philos->id + 1) % (philos->rules->nb_philo);
	if (philos->id % 2)
	{
		philos->forks[0] = (philos->id + 1) % (philos->rules->nb_philo);
		philos->forks[1] = philos->id;
	}
}

/* 
 * init_philos
 * ----------------------------
 *  Initialize the philo struct.
 * 
 *	tabe: struct with general datas.
 */
t_philo	**init_philos(t_rules *rules)
{
	t_philo	**philos;
	int		i;

	philos = malloc(sizeof(t_philo) * rules->nb_philo);
	if (!philos)
		return (print_error_msg(MALLOC_ERROR, "fail to allocate philos", 0));
	i = -1;
	while (++i < rules->nb_philo)
	{
		philos[i] = malloc(sizeof(t_philo) * 1);
		if (!philos[i])
			return (print_error_msg(MALLOC_ERROR, "fail alloc. philos", 0));
		if (pthread_mutex_init(&philos[i]->meal_lock, NULL) != 0)
		{
			print_error_msg(MUTEX_ERROR, "fail to create mutex: meal_lock", 0);
			return (NULL);
		}
		philos[i]->id = i;
		philos[i]->rules = rules;
		philos[i]->times_ate = 0;
		philos[i]->forks = malloc(sizeof(int) * 2);
		asign_forks(philos[i]);
	}
	return (philos);
}

/* 
 * init_mutexes
 * ----------------------------
 *  Initialize mutexes that will be used in the future.
 * 
 * tabe: struct with general datas.
 */
static int	init_mutexes(t_rules *rules)
{
	rules->fork_locks = init_forks(rules);
	if (!rules->fork_locks)
		return (FALSE);
	if (pthread_mutex_init(&rules->sim_stop_lock, 0) != 0)
	{
		print_error_msg(MUTEX_ERROR, "fail to create mutex: sim_stop_lock", 0);
		return (FALSE);
	}
	if (pthread_mutex_init(&rules->write_lock, NULL) != 0)
	{
		print_error_msg(MUTEX_ERROR, "fail to create mutex: write_lock", 0);
		return (FALSE);
	}
	return (TRUE);
}

/* 
 * init_rules
 * ----------------------------
 *  Initialize the struct with the given args.
 * 
 * tabe: struct with general datas.
 */
t_rules	*init_rules(t_rules *rules, int argc, char **argv)
{
	rules = malloc(sizeof(t_rules));
	if (!rules)
		return (print_error_msg(MALLOC_ERROR, NULL, 0), NULL);
	rules->nb_philo = ft_atoi(argv[1]);
	rules->time_to_die = ft_atoi(argv[2]);
	rules->time_to_eat = ft_atoi(argv[3]);
	rules->time_to_sleep = ft_atoi(argv[4]);
	rules->times_x_eat = -1;
	rules->simulation_stop = FALSE;
	if (argc == 5)
		rules->times_x_eat = ft_atoi(argv[5]);
	rules->philos = init_philos(rules);
	if (!rules->philos)
	{
		print_error_msg(THREAD_ERROR, NULL, 0);
		return (NULL);
	}
	if (!init_mutexes(rules))
	{
		free_structs(rules);
		return (NULL);
	}
	rules->simulation_stop = 0;
	return (rules);
}
