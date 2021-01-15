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

typedef struct		s__part_ph
{
	int				name;
	int				t_start;
	int				life;
}					t_part_ph;

typedef struct		s_philo
{
	t_part_ph		*chg_able;
	int				info[5];
}					t_philo;

int					ft_atoi(const char *nptr);
long int			current_time(t_philo *philo);

#endif