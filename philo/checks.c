/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:39:58 by victofer          #+#    #+#             */
/*   Updated: 2023/03/21 18:26:29 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

/* 
 * args_checker
 * ----------------------------
 *	Checks if all given arguments are digits.
 *	If not, print an error and exit program.	
 * 
 *	cant: number of arguments.
 *	args: array with the arguments.
 */
int	args_checker(int cant, char **args)
{
	int	i;
	int	j;

	i = 0;
	while (++i <= cant)
	{
		j = 0;
		while (args[i][j])
		{
			if (!is_digit(args[i][j]))
			{
				print_error_message("ERROR: Bad argument format\n");
				return (-1);
			}
		j++;
		}
	}
	return (0);
}
