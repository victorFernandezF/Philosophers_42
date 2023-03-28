/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:43:43 by victofer          #+#    #+#             */
/*   Updated: 2023/03/28 12:11:53 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


//pthread_mutex_t	mutex ;
/* 
void	*routine(void *args)
{
	t_vars	*tdata;
	int		res;

	tdata = (t_vars *)args;
	res = tdata->time_to_die + 1;
	tdata->time_to_die = res;
	return (NULL);
	//pthread_exit(NULL);
}
	
/* 	int				i;
	t_vars			*vars;

	i = 0;
	vars = (t_vars *)args;
	vars->time_to_die = 27;
	pthread_mutex_lock(&vars->mutex);
	while (i++ < 1000000)
		nb++;
	pthread_mutex_unlock(&vars->mutex);
	return (NULL);


int	create_philo(t_vars *vars)
{
	pthread_t		p;
	//int				i;
	
	pthread_create(&p, NULL, routine, (void *)&vars);
	pthread_join(p, NULL);
	printf("%d\n", vars->time_to_die);

	/* p = (pthread_t *)malloc (vars->nb_philo * sizeof(pthread_t));
	if (!p)
		return (0);
	i = 0;
	pthread_mutex_init(&vars->mutex, NULL);
	printf("before -> %i\n", vars->time_to_die);
	while (i < vars->nb_philo)
	{
		if (pthread_create(&p[i], NULL, &routine, (void *)&vars) != 0)
			return (1);
		//printf("thread %i has started\n", i);
			printf("After -> %i\n", vars->time_to_die);
		i++;
	}
	i = 0;
	while (i < vars->nb_philo)
	{
		pthread_join(p[i], NULL);
		i++;
	}
	pthread_mutex_destroy(&vars->mutex);
	printf("nb -> %i\n", nb);
	return (0); 
}
 */