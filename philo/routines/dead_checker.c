/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 10:02:06 by victofer          #+#    #+#             */
/*   Updated: 2023/04/05 10:34:26 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	sim_stop_flag(t_table *table, int state)
{
	pthread_mutex_lock(&table->sim_stop_lock);
	table->simulation_stop = state;
	pthread_mutex_unlock(&table->sim_stop_lock);
}

static int	kill(t_philo *philo)
{
	time_t	time;

	time = get_timestamp_ms();
	if (time - philo->last_meal >= philo->table->time_to_die)
	{
		sim_stop_flag(philo->table, TRUE);
		write_status(philo, "died");
		return (TRUE);
	}
	return (FALSE);
}

static int	end_of_simulation(t_table *table)
{
	int	i;
	int	all_philo_ate;

	i = 0;
	all_philo_ate = 1;
	while (i < table->nb_philo)
	{
		pthread_mutex_lock(&table->philos[i]->meal_lock);
		if (kill(table->philos[i]) == TRUE)
			return (TRUE);
		if (table->times_x_eat != -1)
			if (table->philos[i]->times_ate < table->times_x_eat)
				all_philo_ate = FALSE;
		pthread_mutex_unlock(&table->philos[i]->meal_lock);
		i++;
	}
	if (table->times_x_eat != -1 && all_philo_ate == TRUE)
	{
		sim_stop_flag(table, TRUE);
		return (TRUE);
	}
	return (FALSE);
}

void	*dead(void *arg)
{
	t_table	*table;

	table = (t_table *)arg;
	if (table->times_x_eat == 0)
		return (NULL);
	sim_stop_flag(table, FALSE);
	while (1)
	{
		if (end_of_simulation(table) == 1)
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}
