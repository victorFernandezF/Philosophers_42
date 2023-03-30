/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:48:21 by victofer          #+#    #+#             */
/*   Updated: 2023/03/30 11:29:59 by victofer         ###   ########.fr       */
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
time_t		get_timestamp_ms(void);

//	S I M U L A T I O N

void		start_philosophers(t_table	*table);

//	C H E C K S

int			number_args_checker(int cant);
int			args_checker(int cant, char **args);

//	E R R O R O S 

void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
int			print_error_msg(char *error, char *details);

//	F R E E   S T U F F

void		free_structs(t_table *table);
void		mutex_destroyer(t_table *table);

//	T E S T I N G   S T U F F    ( D E L E TE ) 

void		leaks(void);

#endif