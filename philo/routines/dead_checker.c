/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 10:02:06 by victofer          #+#    #+#             */
/*   Updated: 2023/04/10 10:43:35 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	sim_stop_flag(t_rules *rules, int state)
{
	pthread_mutex_lock(&rules->sim_stop_lock);
	rules->simulation_stop = state;
	pthread_mutex_unlock(&rules->sim_stop_lock);
}

static int	kill(t_philo *philo)
{
	time_t	time;

	time = get_timestamp_ms();
	if (time - philo->last_meal >= philo->rules->time_to_die)
	{
		sim_stop_flag(philo->rules, TRUE);
		write_status(philo, 1, "died");
		pthread_mutex_unlock(&philo->meal_lock);
		return (TRUE);
	}
	return (FALSE);
}

static int	end_of_simulation(t_rules *rules)
{
	int	i;
	int	all_philo_ate;

	i = 0;
	all_philo_ate = 1;
	while (i < rules->nb_philo)
	{
		pthread_mutex_lock(&rules->philos[i]->meal_lock);
		if (kill(rules->philos[i]))
			return (TRUE);
		if (rules->times_x_eat != -1)
			if (rules->philos[i]->times_ate < rules->times_x_eat)
				all_philo_ate = FALSE;
		pthread_mutex_unlock(&rules->philos[i]->meal_lock);
		i++;
	}
	if (rules->times_x_eat != -1 && all_philo_ate == TRUE)
	{
		sim_stop_flag(rules, TRUE);
		return (TRUE);
	}
	return (FALSE);
}

/* 
 * is_simulation_over
 * ----------------------------
 *  Returns TRUE (1) if simulation is over and FALSE (0)
 * 	if not.
 * 	 
 *	tabe: struct with rules datas.
 */
int	is_simulation_over(t_rules *rules)
{
	int	stop;

	stop = FALSE;
	pthread_mutex_lock(&rules->sim_stop_lock);
	if (rules->simulation_stop == TRUE)
		stop = TRUE;
	pthread_mutex_unlock(&rules->sim_stop_lock);
	return (stop);
}

void	*dead(void *arg)
{
	t_rules	*rules;

	rules = (t_rules *)arg;
	if (rules->times_x_eat == 0)
		return (NULL);
	sim_stop_flag(rules, FALSE);
	delay(rules);
	while (1)
	{
		if (end_of_simulation(rules) == 1)
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}
