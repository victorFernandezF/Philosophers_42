/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Victofer <victofer@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:45:04 by Victofer          #+#    #+#             */
/*   Updated: 2023/04/03 18:45:04 by Victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_status(t_philo *philo, char *status)
{
	printf("%ld %d %s\n", get_timestamp_ms()
		- philo->table->time_start, philo->id + 1, status);
}

void    write_status(t_philo *philo, char *status)
{
    pthread_mutex_lock(philo->table->write_lock);
    print_status(philo, status);
    pthread_mutex_unlock(philo->table->write_lock);
}