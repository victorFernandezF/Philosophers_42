/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_routines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:33:43 by Victofer          #+#    #+#             */
/*   Updated: 2023/04/10 10:43:58 by victofer         ###   ########.fr       */
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
	pthread_mutex_lock(&philo->rules->fork_locks[philo->forks[0]]);
	write_status(philo, 0, "has taken a fork");
	pthread_mutex_lock(&philo->rules->fork_locks[philo->forks[1]]);
	write_status(philo, 0, "has taken a fork");
	write_status(philo, 0, "is eating");
	pthread_mutex_lock(&philo->meal_lock);
	philo->last_meal = get_timestamp_ms();
	pthread_mutex_unlock(&philo->meal_lock);
	philo_wait_time(philo->rules, philo->rules->time_to_eat);
	if (is_simulation_over(philo->rules) == FALSE)
	{
		pthread_mutex_lock(&philo->meal_lock);
		philo->times_ate += 1;
		pthread_mutex_unlock(&philo->meal_lock);
	}
	write_status(philo, 0, "is sleeping");
	pthread_mutex_unlock(&philo->rules->fork_locks[philo->forks[0]]);
	pthread_mutex_unlock(&philo->rules->fork_locks[philo->forks[1]]);
	philo_wait_time(philo->rules, philo->rules->time_to_sleep);
}

/* 
 * think_routine
 * ----------------------------
 *	Calculates the time that philo waist depending on the
 *	rest times and puts philo to think.
 *	
 *	philo
 */
void	think_routine(t_philo *philo, int hide)
{
	time_t	time_think;

	pthread_mutex_lock(&philo->meal_lock);
	time_think = (philo->rules->time_to_die
			- (get_timestamp_ms() - philo->last_meal)
			- philo->rules->time_to_eat) / 2;
	pthread_mutex_unlock(&philo->meal_lock);
	if (time_think < 0)
		time_think = 0;
	if (time_think == 0 && hide == 1)
		time_think = 1;
	if (time_think > 600)
		time_think = 200;
	if (hide == 0)
		write_status(philo, 0, "is thinking");
	philo_wait_time(philo->rules, time_think);
}
