/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:43:43 by victofer          #+#    #+#             */
/*   Updated: 2023/04/03 11:21:24 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/* 
 * start_philosophers
 * ----------------------------
 *  Create one thread for each philo and a thread to
 *  control the deads philos.
 * 
 *	tabe: struct with general datas.
 */
int	start_philosophers(t_table	*table)
{
	int	i;

	i = -1;
	table->time_start = get_timestamp_ms();
	while (++i < table->nb_philo)
	{	
		if (pthread_create(&table->philos[i]->thid, NULL, &general
				, table->philos[i]) != 0)
		{
			print_error_msg(THREAD_ERROR, "fail crating philo threads");
			return (0);
		}
	}
	if (table->nb_philo > 1)
	{
		if (pthread_create(&table->dead_checker, NULL, &dead, table) != 0)
		{
			print_error_msg(THREAD_ERROR, "fail creating dead_checker thread");
			return (0);
		}
	}
	return (1);
}

void	stop_philosophers(t_table	*table)
{
	int	i;

	i = -1;
	while (++i < table->nb_philo)
		pthread_join(table->philos[i]->thid, NULL);
	if (table->nb_philo > 1)
		pthread_join(table->dead_checker, NULL);
	mutex_destroyer(table);
	free_structs(table);
}
