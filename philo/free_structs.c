/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:12:31 by victofer          #+#    #+#             */
/*   Updated: 2023/03/20 18:59:25 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* 
 * free_structs
 * ----------------------------
 *  Frees the struct vars.
 */
void	free_structs(t_vars *vars)
{
	free(vars);
	vars = NULL;
}
