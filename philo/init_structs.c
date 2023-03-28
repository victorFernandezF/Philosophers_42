/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:39:40 by victofer          #+#    #+#             */
/*   Updated: 2023/03/28 18:44:45 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	philos->forks[1] = (philos->id + 1) % (philos->table->nb_philo);
	if (philos->id % 2)
	{
		philos->forks[0] = (philos->id + 1) % (philos->table->nb_philo);
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
t_philo	**init_philos(t_table *table)
{
	t_philo	**philos;
	int		i;

	philos = malloc(sizeof(t_philo) * table->nb_philo);
	if (!philos)
		return (print_error_message(MALLOC_ERROR), NULL);
	i = 0;
	while (i < table->nb_philo)
	{
		philos[i] = malloc(sizeof(t_philo) * 1);
		if (!philos[i])
			return (print_error_message(MALLOC_ERROR), NULL);
		if (pthread_mutex_init(&philos[i]->meal_lock, NULL) != 0)
			return (print_error_message(MALLOC_ERROR), NULL);
		philos[i]->id = i;
		philos[i]->table = table;
		philos[i]->times_ate = 0;
		philos[i]->forks = malloc(sizeof(int) * 2);
		asign_forks(philos[i]);
		i++;
	}
	return (philos);
}

/* 
 * init_table
 * ----------------------------
 *  Initialize the struct with the given args.
 * 
 * tabe: struct with general datas.
 */
t_table	*init_table(t_table *table, int argc, char **argv)
{
	table = malloc(sizeof(t_table));
	if (!table)
		return (print_error_message(MALLOC_ERROR), NULL);
	table->nb_philo = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[1]);
	table->time_to_eat = ft_atoi(argv[2]);
	table->time_to_sleep = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	table->times_x_eat = -1;
	table->simulation_stop = FALSE;
	if (argc == 5)
		table->times_x_eat = ft_atoi(argv[5]);
	table->philos = init_philos(table);
	if (!table->philos)
		return (print_error_message(MALLOC_ERROR), NULL);
	return (table);
}
