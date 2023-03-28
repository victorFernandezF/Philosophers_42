/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:39:40 by victofer          #+#    #+#             */
/*   Updated: 2023/03/28 11:24:05 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* 
 * init_philo_vars
 * ----------------------------
 *  Initialize the struct with the given args.	
 */
t_table	*init_table(t_table *table, int argc, char **argv)
{
	table = malloc(sizeof(table));
	if (!table)
		return (print_error_message("ERROR: Failed creating struct"), NULL);
	table->nb_philo = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[1]);
	table->time_to_eat = ft_atoi(argv[2]);
	table->time_to_sleep = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	table->times_x_eat = -1;
	table->simulation_stop = FALSE;
	if (argc == 5)
		table->times_x_eat = ft_atoi(argv[5]);
	//table->philos = init_philos(table);
	//if (!table->philos)
	//	return (print_error_message("ERROR: Failed creating philos"));
	return (table);
	}
