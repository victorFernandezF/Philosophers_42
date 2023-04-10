/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_destroyer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:06:24 by victofer          #+#    #+#             */
/*   Updated: 2023/04/10 10:45:16 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/* 
 * mutex_destroyer
 * ----------------------------
 *	Destroy all created mutexes.
 * 
 *	rules: struct with general datas.
 */
void	mutex_destroyer(t_rules *rules)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&rules->sim_stop_lock);
	pthread_mutex_destroy(&rules->write_lock);
	while (i < rules->nb_philo)
	{
		pthread_mutex_destroy(&rules->philos[i]->meal_lock);
		pthread_mutex_destroy(&rules->fork_locks[i]);
	i++;
	}
}
