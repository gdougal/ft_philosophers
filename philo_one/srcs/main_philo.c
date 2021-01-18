/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 15:19:25 by gdougal           #+#    #+#             */
/*   Updated: 2021/01/15 15:19:27 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	mutex_wrap_chng(t_philo *phd, void f_chng())
{
	pthread_mutex_lock(&phd->info->chngs);
	f_chng(phd);
	pthread_mutex_unlock(&phd->info->chngs);
}

void	mutex_wrap_writing(t_philo *phd, char * str, int n, void f_write())
{
	pthread_mutex_lock(&phd->info->write);
	f_write(phd, str, n);
	pthread_mutex_unlock(&phd->info->write);
}

void	forks_take(t_philo *phd)
{
	if (phd->name % 2)
	{
		pthread_mutex_lock(&phd->info->forks[phd->waf[RIGHT]]);
		some_bussines(phd, "has taken a fork\n", 17, 0);
		pthread_mutex_lock(&phd->info->forks[phd->waf[LEFT]]);
		some_bussines(phd, "has taken a fork\n", 17, 0);
	}
	else
	{
		pthread_mutex_lock(&phd->info->forks[phd->waf[LEFT]]);
		some_bussines(phd, "has taken a fork\n", 17, 0);
		pthread_mutex_lock(&phd->info->forks[phd->waf[RIGHT]]);
		some_bussines(phd, "has taken a fork\n", 17, 0);
	}
}

void	right_forks_drop(t_philo *phd)
{
	pthread_mutex_unlock(&phd->info->forks[phd->waf[LEFT]]);
	pthread_mutex_unlock(&phd->info->forks[phd->waf[RIGHT]]);
}

void	left_forks_drop(t_philo *phd)
{
	pthread_mutex_unlock(&phd->info->forks[phd->waf[RIGHT]]);
	pthread_mutex_unlock(&phd->info->forks[phd->waf[LEFT]]);
}

void	lifecycle(t_philo *phd)
{
	mutex_wrap_chng(phd, &init_philo);
	while (!every_day_the_same(phd))
	{

	}
}

int		thread_start(t_philo **philo, t_info *info)
{
	int		i;

	i = 0;
	while (i < info->rules[SUM_PH])
	{
		(*philo)[i].name = i + 1;
		(*philo)[i].info = info;
		if (pthread_create(&(*philo)[i].th, NULL, (void *)lifecycle, &(*philo)[i]))
			return (1);
		i++;
	}
//	if (pthread_create(&(*philo)[i].th, NULL, (void *)is_death, info))
//		return (1);
	while (i-- >= 0)
		pthread_join((*philo)[i].th, NULL);
	return (0);
}

int		main(int argc, char **argv)
{
	t_philo			*philo;
	t_info			info;

	if (philo_pars(argv, argc, &info))
		return (1);
	philo = (t_philo * )malloc((info.rules[SUM_PH]) * sizeof(t_philo));
	if (thread_start(&philo, &info))
		return (1);
}