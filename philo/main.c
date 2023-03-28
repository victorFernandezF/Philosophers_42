/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:20:43 by victofer          #+#    #+#             */
/*   Updated: 2023/03/28 10:35:06 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	*t_table;

	t_table = NULL;
	argc--;
	if (number_args_checker(argc) == -1)
		return (-1);
	if (args_checker(argc, argv) == -1)
		return (-1);
	//init_philo_vars(vars, argc, argv);
	//create_philo(vars);
	//free_structs(vars);
	return (0);
}
