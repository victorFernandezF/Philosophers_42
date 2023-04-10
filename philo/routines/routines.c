/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:56:14 by victofer          #+#    #+#             */
/*   Updated: 2023/04/10 10:44:15 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/* 
 * general_routine
 * ----------------------------
 *  A general routine for every thread except dead_checker
 * 	This routine will call the rest depending on the situation.
 */
void	*general_routine(void	*arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->rules->times_x_eat == 0)
		return (NULL);
	pthread_mutex_lock(&philo->meal_lock);
	philo->last_meal = philo->rules->time_start;
	pthread_mutex_unlock(&philo->meal_lock);
	delay(philo->rules);
	if (philo->rules->time_to_die == 0)
		return (NULL);
	if (philo->rules->nb_philo == 1)
	{
		one_and_only(philo);
		return (NULL);
	}
	else if (philo->id % 2)
		think_routine(philo, TRUE);
	while (is_simulation_over(philo->rules) == FALSE)
	{
		eat_sleep_routine(philo);
		think_routine(philo, FALSE);
	}
	return (NULL);
}

/* 
 * one_and_only
 * ----------------------------
 *	This function execcutes if there is only one philosopher.
 *	Philo takes one fork (spoiler: there is only one fork) and is not
 *	able to eat, so philo go to sleep and unfortunately (or not) philo
 *	die. RIP. 
 */
void	*one_and_only(t_philo *philo)
{
	pthread_mutex_lock(&philo->rules->fork_locks[philo->forks[0]]);
	write_status(philo, 0, "has taken a fork");
	philo_wait_time(philo->rules, philo->rules->time_to_die);
	write_status(philo, 0, "died");
	pthread_mutex_unlock(&philo->rules->fork_locks[philo->forks[0]]);
	return (NULL);
}
