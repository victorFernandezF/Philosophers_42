/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:04:17 by victofer          #+#    #+#             */
/*   Updated: 2023/03/20 18:59:33 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* 
 * leaks
 * ----------------------------
 *  This functions is temporal.
 * 	DELETE BEFORE PRESENT
*/
void	leaks(void)
{
	system("leaks -q philo");
}
