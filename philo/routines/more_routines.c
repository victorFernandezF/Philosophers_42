/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_routines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:33:43 by Victofer          #+#    #+#             */
/*   Updated: 2023/04/04 11:55:19 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/* 
 * eat_sleep_routine
 * ----------------------------
 *	Philo takes the forks eats and sleep
 *
 * 	philo
 */
void	eat_sleep_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->fork_locks[0]);
	write_status(philo, "has taken a fork");
	pthread_mutex_lock(&philo->table->fork_locks[1]);
	write_status(philo, "has taken a fork");
	write_status(philo, "is eating");
	pthread_mutex_lock(&philo->meal_lock);
	philo->last_meal = get_timestamp_ms();
	pthread_mutex_unlock(&philo->meal_lock);
	philo_wait_time(philo->table, philo->table->time_to_eat);
	if (is_simulation_stop(philo->table) == 0)
	{
		pthread_mutex_lock(&philo->meal_lock);
		philo->times_ate += 1;
		pthread_mutex_unlock(&philo->meal_lock);
	}
	write_status(philo, "is sleeping");
	pthread_mutex_unlock(&philo->table->fork_locks[0]);
	pthread_mutex_unlock(&philo->table->fork_locks[1]);
	philo_wait_time(philo->table, philo->table->time_to_sleep);
}

/* 
 * think_routine
 * ----------------------------
 *	Calculates the time that philo waist depending on the
 *	rest times and puts philo to think.
 *	
 *	philo
 */
void	think_routine(t_philo *philo)
{
	time_t	time_think;

	pthread_mutex_lock(&philo->meal_lock);
	time_think = (philo->table->time_to_die - (get_timestamp_ms()
				- philo->last_meal - philo->table->time_to_eat) / 2);
	pthread_mutex_unlock(&philo->meal_lock);
	if (time_think < 0)
		time_think = 0;
	if (time_think == 0)
		time_think = 1;
	if (time_think > 600)
		time_think = 200;
	write_status(philo, "is thinking");
	philo_wait_time(philo->table, time_think);
}
