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

#ifndef PHILO_TWO_H
# define PHILO_TWO_H

# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <semaphore.h>

typedef enum
{
	SUM_PH = 0,
	T_DIE = 1,
	T_EAT = 2,
	T_SLEEP = 3,
	T_MST_E = 4,
}	t_indexs;

# define EAT		"is eating\n"
# define SLEEP	"is sleeping\n"
# define THINK	"is thinking\n"
# define DEAD	"is dead\n"
# define TAKE_F	"has taken a fork\n"

typedef struct		s_info
{
	int				amdead;
	int				rules[5];
	sem_t			*forks;
	sem_t			*waiter;
	sem_t			*write;
	sem_t			*l_check;
	sem_t			*last_eat;
	sem_t			*start;
	pthread_t		d_th;
}					t_info;

typedef struct		s_philo
{
	int				name;
	int				must_eat;
	ssize_t			curent_time;
	ssize_t			t_start;
	ssize_t			last_eat;
	pthread_t		th;
	t_info			*info;
}					t_philo;

int					philo_pars(char **argv, int argc, t_info *info);
int					ft_atoi(const char *nptr);
int					thread_start(t_philo **philo, t_info *info);
void				lifecycle(t_philo *phd);
ssize_t				time_start(void);
ssize_t				current_time(t_philo *philo);
void				true_sleep(int wait);
void				life_check(t_philo **phd);
void				dead_status(t_philo *phd);
void				print_dead(t_philo *phd, char *str, int n);
void				init_philo(t_philo *phd);
void				ft_putnbr_light(unsigned int n);
void				forks_take(t_philo *phd);
void				forks_drop(t_philo *phd);
void				every_day_the_same(t_philo *phd);
void				print_t_name(t_philo *phd, char *str, int n);
void				sem_wrap_chng(t_philo *phd, sem_t *type, void f_chng());
void				sem_wrap_writing(t_philo *phd,
						char *str, int n, void f_write());
void				clear_space(int status, t_info *info, t_philo **phd);
void				semaphore_close(t_info *info);
void				semaphore_unlink(void);
#endif
