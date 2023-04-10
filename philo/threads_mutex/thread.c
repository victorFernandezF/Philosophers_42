/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:43:43 by victofer          #+#    #+#             */
/*   Updated: 2023/04/10 10:45:24 by victofer         ###   ########.fr       */
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
int	start_philosophers(t_rules	*rules)
{
	int	i;

	i = -1;
	rules->time_start = get_timestamp_ms() + (rules->nb_philo * 2 * 10);
	while (++i < rules->nb_philo)
	{	
		if (pthread_create(&rules->philos[i]->thid, NULL, &general_routine
				, rules->philos[i]) != 0)
		{
			print_error_msg(THREAD_ERROR, "fail crating philo threads", 0);
			return (0);
		}
	}
	if (rules->nb_philo > 1)
	{
		if (pthread_create(&rules->dead_checker, NULL, &dead, rules) != 0)
		{
			print_error_msg(THREAD_ERROR, "fail dead_checker thread", 0);
			return (0);
		}
	}
	return (1);
}

/* 
 * stop_philosophers
 * ----------------------------
 *  Wait till all threads finish their stuff.
 * 	Destroys mutexes and frees memory.
 *	Now program is ready to finish correctly.
 * 
 *	tabe: struct with general datas.
 */
void	stop_philosophers(t_rules	*rules)
{
	int	i;

	i = -1;
	while (++i < rules->nb_philo)
		pthread_join(rules->philos[i]->thid, NULL);
	if (rules->nb_philo > 1)
		pthread_join(rules->dead_checker, NULL);
	mutex_destroyer(rules);
	free_structs(rules);
}
