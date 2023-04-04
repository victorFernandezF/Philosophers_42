/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:56:14 by victofer          #+#    #+#             */
/*   Updated: 2023/04/04 11:18:32 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/* 
 * general
 * ----------------------------
 *  A general routine for every thread except dead_checker
 * 	This routine will call the rest depending on the situation.
 */
void	*general(void	*arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->table->times_x_eat == 0)
		return (NULL);
	pthread_mutex_lock(&philo->meal_lock);
	philo->last_meal = philo->table->time_start;
	pthread_mutex_unlock(&philo->meal_lock);
	if (philo->table->time_to_die == 0)
		return (NULL);
	if (philo->table->nb_philo == 1)
		one_and_only(philo);
	else if (philo->id % 2 == 0)
		think_routine(philo);
	while (is_simulation_stop(philo->table) == FALSE)
	{
		eat_sleep_routine(philo);
		think_routine(philo);
	}
	return (NULL);
}

/* 
 * dead
 * ----------------------------
 *	A routine for the dead_checker.
 *	It will checks if any philo decided to die.
 */
void	*dead(void	*arg)
{
	pthread_t	id;

	id = (pthread_t)arg;
	//printf("%lld", id);
	return (NULL);
}

/* 
 * philo_sleep
 * ----------------------------
 *	Calculate the time that a philo has to sleep
 *	and puts philo to spleep
 */
void	philo_wait_time(t_table *table, time_t wait_time)
{
	time_t	wait;

	wait = get_timestamp_ms() + wait_time;
	while (get_timestamp_ms() < wait)
	{
		if (is_simulation_stop(table))
			break ;
		usleep(100);
	}
}

/* 
 * one_and_only
 * ----------------------------
 *	This function execcutes if there is only one philosopher.
 *	Philo takes one fork (spoiler: there is only one fork) and is not
 *	able to eat, so philo go to sleep and unfortunately (or not) philo
 *	die. RIP. 
 */
void	*one_and_only(void	*arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->table->fork_locks[philo->forks[0]]);
	print_status(philo, "has taken a fork");
	philo_wait_time(philo->table, philo->table->time_to_die);
	print_status(philo, "died");
	pthread_mutex_unlock(&philo->table->fork_locks[philo->forks[0]]);
	return (NULL);
}
