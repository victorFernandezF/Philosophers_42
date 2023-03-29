/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:22:45 by victofer          #+#    #+#             */
/*   Updated: 2023/03/29 12:03:24 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* 
 * ft_putchar_fd
 * ----------------------------
 *  Writes the given char in the given file descriptor.
 * 
 *	c: char to be written.	
 *	fd: file descripto where c wil be written.	
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(c));
}

/* 
 * ft_putstr_fd
 * ----------------------------
 *  Writes the given string in the given file descriptor.
 * 
 *	s: string to be written.	
 *	fd: file descripto where c wil be written.	
 */
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
 *  Writes 'Error' followed by the error message.
 * 
 *	error: error message to be shown.	
 */
int	print_error_msg(char *error, char *details)
{
	ft_putstr_fd("\033[1;31m ERROR: ", 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd("\033[0m \n", 2);
	if (details != NULL)
	{
		ft_putstr_fd("\033[0;33m \t", 2);
		ft_putstr_fd(details, 2);
		ft_putstr_fd("\033[0m \n\n", 2);
	}
	return (-1);
}

