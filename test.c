/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:19:06 by victofer          #+#    #+#             */
/*   Updated: 2023/03/28 12:24:22 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>

int				nb = 0;

typedef struct s_mutex
{
	pthread_mutex_t	mutex;
}					t_mutex;

long int	get_timestamp_ms(void);

void	*routine(void *arg)
{
	int		i;
	t_mutex	*mutex;

	mutex = (t_mutex *)arg;
	i = 0;
	(void)arg;
	pthread_mutex_lock(&mutex->mutex);
	while (i++ < 1000000)
		nb++;
	pthread_mutex_unlock(&mutex->mutex);
	return (0);
}

int	main(void)
{
	pthread_t		p[5];
	t_mutex			*mutex;
	int				i;

	printf("%i\n", 3 % 4);
	i = 0;
	mutex = malloc(sizeof(t_mutex));
	pthread_mutex_init(&mutex->mutex, NULL);
	while (i < 4)
	{
		if (pthread_create(&p[i], NULL, &routine, &mutex->mutex) != 0)
			return (1);
		printf("thread %i has started\n", i);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		pthread_join(p[i], NULL);
		i++;
	}
	pthread_mutex_destroy(&mutex->mutex);
	printf("nb -> %i", nb);
	return (0);
}
