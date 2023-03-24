/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:48:21 by victofer          #+#    #+#             */
/*   Updated: 2023/03/22 18:10:06 by victofer         ###   ########.fr       */
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
void		init_philo_vars(t_vars *vars, int argc, char **argv);
long int	get_timestamp_ms(void);
int			create_philo(t_vars *vars);
void		*routine(void *args);



//	C H E C K S

int			args_checker(int cant, char **args);

//	E R R O R O S 

void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		print_error_message(char *error);

//	F R E E   S T U F F

void		free_structs(t_vars *vars);

//	T E S T I N G   S T U F F    ( D E L E TE ) 

void		leaks(void);

#endif