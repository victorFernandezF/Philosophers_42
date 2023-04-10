/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:45:04 by Victofer          #+#    #+#             */
/*   Updated: 2023/04/10 10:45:47 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/* 
 * print_status
 * ----------------------------
 *  Prints the status with the correct format:
 * 	-> [timestamp] [philo name] [status]
 * 	(example: 200 1 is eating) 
 * 
 *	philo: struct with rules datas.
 *	status: status to print: is eating, is sleeping, died...
 */
void	print_status(t_philo *philo, char *status)
{
	printf("%ld %d %s\n", get_timestamp_ms()
		- philo->rules->time_start, philo->id + 1, status);
}

/* 
 * write_status
 * ----------------------------
 *  Locks the write mutex. Prints the status with the
 * 	help of print_status function and unlock the write mutex.
 * 
 *	philo: struct with rules datas.
 *	status: status to print: is eating, is sleeping, died...
 */
void	write_status(t_philo *philo, int dead, char *status)
{
	pthread_mutex_lock(&philo->rules->write_lock);
	if (is_simulation_over(philo->rules) == 1 && dead == 0)
	{
		pthread_mutex_unlock(&philo->rules->write_lock);
		return ;
	}
	print_status(philo, status);
	pthread_mutex_unlock(&philo->rules->write_lock);
}
