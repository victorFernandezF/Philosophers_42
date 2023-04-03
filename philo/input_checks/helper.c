/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:08:51 by victofer          #+#    #+#             */
/*   Updated: 2023/04/03 13:55:18 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/* 
 * helper
 * ----------------------------
 *	Shows a litle guide with the parameters that
 *	this program acepts and its order.
 */
void	helper(void)
{
	printf(GREEN"-----------------------------\n");
	printf(GREEN"|  WELCOME TO PHILOSOPHERS  |\n|");
	printf(BG"   This is a litle guide   ");
	printf(GREEN"|\n");
	printf(GREEN"-----------------------------\n");
	printf(BLUE"-----------------\n");
	printf(BLUE"|  ** PARAMS **  |\n");
	printf(BLUE"|--------------------------------------------------------\n");
	printf(BLUE"| -> [1] number of philosophers                         |\n");
	printf(BLUE"| -> [2] time to die                                    |\n");
	printf(BLUE"| -> [3] time to eat                                    |\n");
	printf(BLUE"| -> [4] time to sleep                                  |\n");
	printf(BLUE"| -> [5] [optional] number of times each philo must eat |\n");
	printf(BLUE"---------------------------------------------------------\n");
	printf(W" \n");

}
