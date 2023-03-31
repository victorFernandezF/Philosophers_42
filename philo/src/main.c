/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:20:43 by victofer          #+#    #+#             */
/*   Updated: 2023/03/31 11:23:53 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_table	*table;

	atexit(leaks);
	table = NULL;
	argc--;
	if (input_checker(argc, argv) == -1)
		return (-1);
	table = init_table(table, argc, argv);
	if (!table)
	{
		free_structs(table);
		return (-1);
	}
	if (!start_philosophers(table))
		return (-1);
	stop_philosophers(table);
	return (0);
}
