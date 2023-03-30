/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:03:50 by victofer          #+#    #+#             */
/*   Updated: 2023/03/30 10:14:25 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	ft_is_sign(char n)
{
	if (n == '+' || n == '-')
		return (1);
	return (0);
}

static int	ft_is_nbr(char n)
{
	if (n >= 48 && n <= 57)
		return (1);
	return (0);
}

/* 
 * ft_atoi
 * ----------------------------
 *  Converts a string in an ineger.
 * 
 *	str: string with the digits to convert.	
 */
long long	ft_atoi(const char *str)
{
	long long	result;
	int			sign;
	long long	i;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (ft_is_sign(str[i]))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_is_nbr(str[i]))
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}
