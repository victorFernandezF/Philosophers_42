/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:20:43 by victofer          #+#    #+#             */
/*   Updated: 2023/04/10 10:50:45 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_rules	*rules;

	rules = NULL;
	argc--;
	if (input_checker(argc, argv) == -1)
		return (-1);
	rules = init_rules(rules, argc, argv);
	if (!rules)
	{
		free_structs(rules);
		return (-1);
	}
	if (!start_philosophers(rules))
		return (-1);
	stop_philosophers(rules);
	return (0);
}
