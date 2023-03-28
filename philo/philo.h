/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:48:21 by victofer          #+#    #+#             */
/*   Updated: 2023/03/28 12:44:48 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "structs.h"
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

//	I N I T 

long long	ft_atoi(const char *str);
t_table		*init_table(t_table *table, int argc, char **argv);
t_philo		**init_philos(t_table *table);
void		asign_forks(t_philo *philos);
long int	get_timestamp_ms(void);
//int			create_philo(t_vars *vars);
void		*routine(void *args);



//	C H E C K S

int			number_args_checker(int cant);
int			args_checker(int cant, char **args);

//	E R R O R O S 

void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		print_error_message(char *error);

//	F R E E   S T U F F

void		free_structs(t_table *table);

//	T E S T I N G   S T U F F    ( D E L E TE ) 

void		leaks(void);

#endif