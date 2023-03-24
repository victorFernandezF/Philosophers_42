/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:55:51 by victofer          #+#    #+#             */
/*   Updated: 2023/03/23 11:47:13 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>

typedef struct s_thread_data {
	int				a;
	int				nb;
	pthread_mutex_t	mu;
}		t_thread_data;

void	*my_thread(void *arg)
{
	t_thread_data	*tdata;
	int				a;

	tdata = (t_thread_data *)arg;
	pthread_mutex_lock(&tdata->mu);
	a = tdata->a;
	a += 1;
	tdata->a = a;
	printf("id inside the thread ->%i\n", tdata->nb);
	printf("NB %i has incremented a by 1 so a = %i\n", tdata->nb, tdata->a);
	pthread_mutex_unlock(&tdata->mu);
	return (NULL);
}

int	main(void)
{
	pthread_t		tid[2];
	t_thread_data	tdata;
	int				i;

	i = -1;
	tdata.a = 0;
	printf(" BEFORE %d\n", tdata.a);
	pthread_mutex_init(&tdata.mu, NULL);
	while (++i < 2)
	{
		tdata.nb = i;
		printf("id ->%i\n", tdata.nb);
		pthread_create(&tid[i], NULL, my_thread, (void *)&tdata);
		printf("%i has started\n", i);
	}
	i = -1;
	while (++i < 1)
		pthread_join(tid[i], NULL);
	printf(" AFTER %d \n", tdata.a);
	pthread_mutex_destroy(&tdata.mu);
	return (0);
}
