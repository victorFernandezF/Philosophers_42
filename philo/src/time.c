/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:32:34 by victofer          #+#    #+#             */
/*   Updated: 2023/04/05 11:02:19 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/* 
 * get_timestamp_ms
 * ----------------------------
 *   Returns the current timestamp converted to miliseconds.
 */
time_t	get_timestamp_ms(void)
{
	struct timeval	cur;

	gettimeofday(&cur, NULL);
	return ((cur.tv_sec * 1000) + (cur.tv_usec / 1000));
}

void	delay(t_table *table)
{
	while (get_timestamp_ms() < table->time_start)
		continue ;
}

/* 
 * philo_sleep
 * ----------------------------
 *	Calculate the time that a philo has to sleep
 *	and puts philo to spleep
 */
void	philo_wait_time(t_table *table, time_t sleep_time)
{
	time_t	wake_up;

	wake_up = get_timestamp_ms() + sleep_time;
	while (get_timestamp_ms() < wake_up)
	{
		if (is_simulation_over(table))
			break ;
		usleep(100);
	}
}