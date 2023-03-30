/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:32:34 by victofer          #+#    #+#             */
/*   Updated: 2023/03/30 11:37:40 by victofer         ###   ########.fr       */
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
	return ((cur.tv_sec * 1000) + (cur.tv_sec / 1000));
}
