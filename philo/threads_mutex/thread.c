/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Victofer <victofer@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:43:43 by victofer          #+#    #+#             */
/*   Updated: 2023/04/03 17:22:50 by Victofer         ###   ########.fr       */
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

int	is_simulation_stop(t_table *table)
{
	int	stop;

	stop = FALSE;
	pthread_mutex_lock(&table->sim_stop_lock);
	if (table->simulation_stop == TRUE)
		stop = TRUE;
	pthread_mutex_unlock(&table->sim_stop_lock);
	return (stop);
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
