/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:39:58 by victofer          #+#    #+#             */
/*   Updated: 2023/03/28 18:41:56 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* 
 * is_digit
 * ----------------------------
 *	Returns 1 if char is a digit and 0 of not.
 */
static int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

/* 
 * args_checker
 * ----------------------------
 *	Checks if all given arguments are digits.
 *	If not, print an error and returns -1.
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
				print_error_message(ARGS_FORMAT_ERROR);
				return (-1);
			}
		j++;
		}
	}
	return (0);
}

/* 
 * num_args_checker
 * ----------------------------
 *	Checks if the number of given arguments is correct.
 *	If not, print an error and returns -1.	
 * 
 *	cant: number of arguments.
 */
int	number_args_checker(int cant)
{
	if (cant != 5 && cant != 4)
	{
		print_error_message(NUM_ARGS_ERROR);
		return (-1);
	}
	return (0);
}
