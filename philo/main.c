/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:20:43 by victofer          #+#    #+#             */
/*   Updated: 2023/03/28 11:26:23 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	*table;

	table = NULL;
	argc--;
	if (number_args_checker(argc) == -1)
		return (-1);
	if (args_checker(argc, argv) == -1)
		return (-1);
	table = init_table(table, argc, argv);
	//create_philo(vars);
	free_structs(table);
	atexit(leaks);
	return (0);
}
