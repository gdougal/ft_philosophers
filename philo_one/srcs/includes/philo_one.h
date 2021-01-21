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

typedef enum
{
	SUM_PH = 0,
	T_DIE = 1,
	T_EAT = 2,
	T_SLEEP = 3,
	T_MST_E = 4,
	LEFT = 0,
	RIGHT = 1
}	t_enum;

//#define SUM_PH	0
//#define T_DIE	1
//#define T_EAT	2
//#define T_SLEEP	3
//#define T_MST_E	4

//#define LEFT	0
//#define RIGHT	1

#define EAT	"is eating\n"
#define SLEEP	"is sleeping\n"
#define THINK	"is thinking\n"
#define DEAD	"is dead\n"
#define TAKE_R_F	"has taken a right fork\n"
#define TAKE_L_F	"has taken a left fork\n"
#define DROP_R_F	"has dropped a right fork\n"
#define DROP_L_F	"has dropped a left fork\n"

typedef struct		s_info
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	write;
	pthread_mutex_t	l_check;
	pthread_mutex_t	last_eat;
	pthread_mutex_t	chng;
	pthread_mutex_t fork;
	pthread_t		d_th;
	int				amdead;
	int				start;
	int				rules[5];
}					t_info;

typedef struct		s_philo
{
	int				name;
	int				waf[2];
	int				must_eat;
	ssize_t			curent_time;
	ssize_t			t_start;
	ssize_t			last_eat;
	pthread_t		th;
	t_info			*info;
}					t_philo;

int					philo_pars(char **argv, int argc, t_info *info);
int					ft_atoi(const char *nptr);
ssize_t				time_start(void);
ssize_t				current_time(t_philo *philo);
void				true_sleep(int wait, ssize_t last_eat, t_philo *phd);
void				life_check(t_philo **phd);
void				before_eat(t_philo *phd);
void				after_eat(t_philo *phd);
void				init_philo(t_philo *phd);
void				ft_putnbr_light(unsigned int n);
void				forks_take(t_philo *phd, int hand_1, int hand_2);
void				forks_drop(t_philo *phd, int hand_1, int hand_2);
void				every_day_the_same(t_philo *phd);
void				print_t_name(t_philo *phd, char *str, int n);
void				mutex_wrap_chng(t_philo *phd, pthread_mutex_t *type, void f_chng());
void				mutex_wrap_writing(t_philo *phd, char * str, int n, void f_write());
int					life_status(t_philo *phd);
int					status(t_info *info);
void				change_status(t_info *info);
#endif