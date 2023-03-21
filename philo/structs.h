/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:49:04 by victofer          #+#    #+#             */
/*   Updated: 2023/03/21 18:21:30 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# define TRUE = 1;
# define FALSE = 0;

//   S T R U C T U R E S

typedef struct s_vars
{
	int	nb_philo;
	int	nb_forks;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	times_x_eat;
}		t_vars;

#endif