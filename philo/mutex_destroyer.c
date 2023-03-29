/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_destroyer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:06:24 by victofer          #+#    #+#             */
/*   Updated: 2023/03/29 10:13:49 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutex_destroyer(t_table *table)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&table->sim_stop_lock);
	pthread_mutex_destroy(&table->write_lock);
	while (i < table->nb_philo)
	{
		pthread_mutex_destroy(&table->philos[i]->meal_lock);
		pthread_mutex_destroy(&table->fork_locks[i]);
	}
	ft_putstr_fd("Muutexes destroyed successfully", 2);
}
