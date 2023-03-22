/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:39:40 by victofer          #+#    #+#             */
/*   Updated: 2023/03/22 11:34:58 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* 
 * init_philo_vars
 * ----------------------------
 *  Initialize the struct with the given args.	
 */
void	init_philo_vars(t_vars *vars, int argc, char **argv)
{
	vars->nb_philo = ft_atoi(argv[1]);
	vars->nb_forks = ft_atoi(argv[1]);
	vars->time_to_die = ft_atoi(argv[2]);
	vars->time_to_eat = ft_atoi(argv[3]);
	vars->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 5)
		vars->times_x_eat = ft_atoi(argv[5]);
	else
		vars->times_x_eat = -1;
}
