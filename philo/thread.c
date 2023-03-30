/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:43:43 by victofer          #+#    #+#             */
/*   Updated: 2023/03/30 10:03:52 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*sim(void	*arg)
{
	(void)arg;
}

void	start_philosophers(t_table	*table)
{
	int	i;

	i = -1;
	table->time_start = get_timestamp_ms;
	while (++i < table->nb_philo)
	{	
		if (pthread_create(&table->philos[i]->th, NULL, &sim, table) != 0)
		{
			print_error_msg(PHILO_ERROR, "fail crating threads");
			return ;
		}
	}
}
