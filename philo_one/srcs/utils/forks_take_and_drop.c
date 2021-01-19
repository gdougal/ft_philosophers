/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_take_and_drop.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 02:29:51 by gdougal           #+#    #+#             */
/*   Updated: 2021/01/19 02:29:53 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	forks_take(t_philo *phd)
{
	if (phd->info->amdead)
		return ;
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
	if (phd->info->start == 1)
		phd->info->start = 2;
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
