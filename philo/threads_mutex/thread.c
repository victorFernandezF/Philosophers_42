/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:43:43 by victofer          #+#    #+#             */
/*   Updated: 2023/03/30 11:42:50 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	*sim(void	*arg)
{
	(void)arg;
	return (NULL);
}

/* 
 * start_philosophers
 * ----------------------------
 *  Create one thread for each philo and a thread to
 *  control the deads philos.
 * 
 *	tabe: struct with general datas.
 */
void	start_philosophers(t_table	*table)
{
	int	i;

	i = -1;
	table->time_start = (long long)get_timestamp_ms;
	while (++i < table->nb_philo)
	{	
		if (pthread_create(&table->philos[i]->th, NULL, &sim, table) != 0)
		{
			print_error_msg(THREAD_ERROR, "fail crating philo threads");
			return ;
		}
	}
	if (table->nb_philo > 1)
	{
		if (pthread_create(&table->dead_checker, NULL, &sim, table) != 0)
		{
			print_error_msg(THREAD_ERROR, "fail creating dead_checker thread");
			return ;
		}
	}	
}
