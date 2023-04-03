/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:56:14 by victofer          #+#    #+#             */
/*   Updated: 2023/04/03 12:23:31 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*general(void	*arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->table->nb_philo == 1)
		one_and_only(philo);
	return (NULL);
}

void	*dead(void	*arg)
{
	pthread_t	id;

	id = (pthread_t)arg;
	return (NULL);
}

void	philo_sleep(t_philo *philo)
{
	time_t	sleeping;

	sleeping = get_timestamp_ms() + philo->table->time_to_sleep;
	while (get_timestamp_ms() < sleeping)
	{
		usleep(100);
	}
}

void	*one_and_only(void	*arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->table->fork_locks[philo->forks[0]]);
	print_status(philo, "has taken a fork");
	philo_sleep(philo);
	print_status(philo, "died");
	pthread_mutex_unlock(&philo->table->fork_locks[philo->forks[0]]);
	return (NULL);
}
