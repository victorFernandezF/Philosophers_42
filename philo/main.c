/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:20:43 by victofer          #+#    #+#             */
/*   Updated: 2023/03/21 18:58:05 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_vars			*vars;

	vars = (t_vars *)malloc(sizeof(t_vars));
	argc--;
	if (argc != 5 && argc != 4)
	{
		print_error_message("ERROR: Incorrect number of arguments\n");
		return (-1);
	}	
	if (args_checker(argc, argv) == -1)
		return (-1);
	init_philo_vars(vars, argc, argv);
	create_philo(vars);
	free_structs(vars);
	return (0);
}
