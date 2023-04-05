/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:08:51 by victofer          #+#    #+#             */
/*   Updated: 2023/04/05 10:00:18 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	param_general_info(void)
{
	printf(BM"------------------------\n");
	printf(BM"| PARAMS GENERAL INFO  |\n");
	printf(BM"|-------------------------------------------------------\n");
	printf(BM"| * Number of parameters acepted: 4 or 5               |\n");
	printf(BM"| * Only digits acepted                                |\n");
	printf(BM"| * Not negatives numbers acepted                      |\n");
	printf(BM"|                                                      |\n");
	printf(BM"|        Example: ./philo 5 800 300 100                |\n");
	printf(BM"--------------------------------------------------------\n");
	printf(W" \n");
}

static void	param_more_info(void)
{
	printf(B"-----------------\n");
	printf(B"|  ** PARAMS **  |\n");
	printf(B"|--------------------------------------------------------\n");
	printf(B"| -> [1] number of philosophers                         |\n");
	printf(B"| -> [2] time to die                                    |\n");
	printf(B"| -> [3] time to eat                                    |\n");
	printf(B"| -> [4] time to sleep                                  |\n");
	printf(B"| -> [5] [optional] number of times each philo must eat |\n");
	printf(B"---------------------------------------------------------\n");
	printf(W" \n");
}

/* 
 * helper
 * ----------------------------
 *	Shows a litle guide with the parameters that
 *	this program acepts and its order.
 */
void	helper(void)
{
	printf(G"-----------------------------\n");
	printf(G"|  WELCOME TO PHILOSOPHERS  |\n|");
	printf(BG"   This is a litle guide   ");
	printf(G"|\n");
	printf(G"-----------------------------\n");
	param_general_info();
	param_more_info();
}
