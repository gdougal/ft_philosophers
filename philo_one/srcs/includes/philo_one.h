/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 15:20:29 by gdougal           #+#    #+#             */
/*   Updated: 2021/01/15 15:20:30 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <string.h>

#define SUM_PH	0
#define T_DIE	1
#define T_EAT	2
#define T_SLEEP	3
#define T_MST_E	4

typedef struct		s_info
{
	int				death;
	pthread_mutex_t	*forks;
	int				rules[5];
}					t_info;

typedef struct		s_philo
{
	int				name;
	int				t_start;
	pthread_t		th;
	ssize_t			last_eat;
	t_info			*info;
}					t_philo;

int					philo_pars(char **argv, int argc, t_info *info);
int					ft_atoi(const char *nptr);
ssize_t 			time_start(void);
long int			current_time(t_philo *philo);
void				init_philo(t_part_ph **phil, int i);


#endif