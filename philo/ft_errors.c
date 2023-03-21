/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:22:45 by victofer          #+#    #+#             */
/*   Updated: 2023/03/21 18:23:34 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(c));
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

/* 
 * ft_error_and_exit
 * ----------------------------
 *  Write 'Error' followed by the error message and then exit
 *  the program.
 * 
 *	error: error message to be shown.	
 */
void	print_error_message(char *error)
{
	ft_putstr_fd(error, 2);
}
