/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:20:43 by victofer          #+#    #+#             */
/*   Updated: 2023/03/30 11:51:44 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_table	*table;

	atexit(leaks);
	table = NULL;
	argc--;
	if (number_args_checker(argc) == -1)
		return (-1);
	if (args_checker(argc, argv) == -1)
		return (-1);
	table = init_table(table, argc, argv);
	if (!table)
	{
		free_structs(table);
		return (-1);
	}
	start_philosophers(table);
	mutex_destroyer(table);
	free_structs(table);
	return (0);
}
