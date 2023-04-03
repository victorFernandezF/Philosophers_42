/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Victofer <victofer@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:20:43 by victofer          #+#    #+#             */
/*   Updated: 2023/04/03 16:50:05 by Victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_table	*table;

	//atexit(leaks);
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
