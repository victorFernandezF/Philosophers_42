/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:43:43 by victofer          #+#    #+#             */
/*   Updated: 2023/03/22 12:18:38 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		nb = 0;

void	*routine(void *arg)
{
	int		i;
	t_vars	*mutex;

	mutex = (t_vars *)arg;
	i = 0;
	(void)arg;
	pthread_mutex_lock(&mutex->mutex);
	while (i++ < 1000000)
		nb++;
	pthread_mutex_unlock(&mutex->mutex);
	return (0);
}

int	create_philo(t_vars *vars)
{
	pthread_t	*p;
	int			i;

	p = (pthread_t *)malloc (vars->nb_philo * sizeof(pthread_t));
	if (!p)
		return (0);
	i = 0;
	pthread_mutex_init(&vars->mutex, NULL);
	while (i < vars->nb_philo)
	{
		if (pthread_create(&p[i], NULL, &routine, &vars->mutex) != 0)
			return (1);
		printf("thread %i created wiii\n", i);
		i++;
	}
	i = 0;
	while (i < vars->nb_philo)
	{
		pthread_join(p[i], NULL);
		i++;
	}
	pthread_mutex_destroy(&vars->mutex);
	printf("%i\n", nb);
	return (0);
}
