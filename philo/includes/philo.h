/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Victofer <victofer@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:48:21 by victofer          #+#    #+#             */
/*   Updated: 2023/04/03 17:35:38 by Victofer         ###   ########.fr       */
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

//	I N I T 

long long	ft_atoi(const char *str);
t_table		*init_table(t_table *table, int argc, char **argv);
t_philo		**init_philos(t_table *table);
void		asign_forks(t_philo *philos);
time_t		get_timestamp_ms(void);

//	S I M U L A T I O N

int			start_philosophers(t_table	*table);
void		stop_philosophers(t_table	*table);
void		print_status(t_philo *philos, char *status);
int			only_one_philo(t_table *table);
int	        is_simulation_stop(t_table *table);

//	R O U T I N E S 

void		*general(void	*arg);
void		*dead(void	*arg);
void		*one_and_only(void	*arg);
void	    philo_wait_time(t_table *table, time_t wait_time);

//	C H E C K S

int			number_args_checker(int cant);
int			args_format_checker(int cant, char **args);
int			input_checker(int cant, char **args);
void		helper(void);


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