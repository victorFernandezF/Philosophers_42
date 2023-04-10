/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:12:31 by victofer          #+#    #+#             */
/*   Updated: 2023/04/10 10:44:58 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/* 
 * free_structs
 * ----------------------------
 *  Frees the struct rules and its content.
 * 
 *	rules: struct with basic datas.
 */
void	free_structs(t_rules *rules)
{
	int	i;

	if (rules == NULL)
		return ;
	if (rules->fork_locks != NULL)
		free(rules->fork_locks);
	if (rules->philos != NULL)
	{
		i = 0;
		while (i < rules->nb_philo)
		{
			if (rules->philos[i]->forks != NULL)
				free(rules->philos[i]->forks);
			if (rules->philos[i] != NULL)
				free(rules->philos[i]);
			i++;
		}
		free(rules->philos);
	}
	free(rules);
	rules = NULL;
	return ;
}
