/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:12:31 by victofer          #+#    #+#             */
/*   Updated: 2023/03/28 12:11:09 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* 
 * free_structs
 * ----------------------------
 *  Frees the struct table and its content.
 */
void	free_structs(t_table *table)
{
	int	i;

	if (!table)
		return ;
	if (table->fork_locks != NULL)
		free(table->fork_locks);
	if (table->philos != NULL)
	{
		i = 0;
		while (i < table->nb_philo)
		{
			if (table->philos[i]->forks != NULL)
				free(table->philos[i]->forks);
			if (table->philos[i] != NULL)
				free(table->philos[i]);
			i++;
		}
		free(table->philos);
	}
	free(table);
	return ;
}
