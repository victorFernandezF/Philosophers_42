/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:32:34 by victofer          #+#    #+#             */
/*   Updated: 2023/03/20 18:53:54 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* 
 * get_timestamp_ms
 * ----------------------------
 *   Returns the current timestamp converted to miliseconds.
 */
long int	get_timestamp_ms(void)
{
	struct timeval	cur;

	gettimeofday(&cur, NULL);
	return (1000 * cur.tv_sec);
}