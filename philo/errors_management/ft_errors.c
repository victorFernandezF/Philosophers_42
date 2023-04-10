/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:22:45 by victofer          #+#    #+#             */
/*   Updated: 2023/04/10 10:38:10 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/* 
 * ft_error_and_exit
 * ----------------------------
 *  Writes 'Error' followed by the error message and optional
 * 	details of the error.
 * 
 *	error: error message to be shown.
 *	details: a string with some details of the error. this
 *			argument can be NULL.	
 */
void	*print_error_msg(char *error, char *details, int input_err)
{
	if (error == NULL)
		error = GENERIC_ERROR;
	printf("%sERROR: %s%s\n", R, error, W);
	if (details != NULL)
	{
		printf("%s\t%s%s\n", Y, details, W);
		if (input_err)
			printf("%s\t type philo -h to see a guide %s\n\n", B, W);
	}
	return (NULL);
}
