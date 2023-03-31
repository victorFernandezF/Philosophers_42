/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:39:58 by victofer          #+#    #+#             */
/*   Updated: 2023/03/31 11:03:31 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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
 * args_neg_checker
 * ----------------------------
 *	Prints an error message and returns 0 if one or more
 * 	arguments are negative numbers. If not, returns 0;
 *
 *	cant: number of args (argc -1)
 *	args: argument to be checked.
 */
int	args_neg_checker(int cant, char **args)
{
	int	i;

	i = -1;
	if (ft_atoi(args[1]) < 0)
	{
		print_error_msg(INPUT_ERROR, "Really? negative philosophers?");
		return (-1);
	}
	while (++i <= cant)
	{
		if (ft_atoi(args[i]) < 0)
		{
			print_error_msg(INPUT_ERROR, "Negatives numbers are not allowed");
			return (-1);
		}
	}
	return (0);
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
int	args_format_checker(int cant, char **args)
{
	int	i;
	int	j;

	i = 0;
	while (++i <= cant)
	{
		j = -1;
		while (args[i][j])
		{
			if (!is_digit(args[i][++j]))
			{
				print_error_msg(INPUT_ERROR, "Arguments must be digits");
				return (-1);
			}
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
		print_error_msg(INPUT_ERROR, "This program acepts 4 or 5 arguments");
		return (-1);
	}
	return (0);
}

/* 
 * input_checker
 * ----------------------------
 *	Makes some general checks to the given arguments.
 *	-> Checks correct number of args.
 *	-> Checks correct format.
 *	-> Checks negatives numbers.
 *	If everything is OK returns 0. If not, returns 1
 *
 *	cant: number of args (argc -1)
 *	args: argument to be checked.
 */
int	input_checker(int cant, char **args)
{
	if (number_args_checker(cant) == -1)
		return (-1);
	if (args_format_checker(cant, args) == -1)
		return (-1);
	if (args_neg_checker(cant, args) == -1)
		return (-1);
	return (0);
}
