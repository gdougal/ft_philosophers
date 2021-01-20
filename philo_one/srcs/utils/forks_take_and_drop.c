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
	if (phd->name % 2)
	{
		pthread_mutex_lock(&phd->info->forks[phd->waf[RIGHT]]);
		mutex_wrap_writing(phd, TAKE_R_F, 23, print_t_name);
		pthread_mutex_lock(&phd->info->forks[phd->waf[LEFT]]);
		mutex_wrap_writing(phd, TAKE_L_F, 22, print_t_name);
	}
	else
	{
		pthread_mutex_lock(&phd->info->forks[phd->waf[LEFT]]);
		mutex_wrap_writing(phd, TAKE_L_F, 22, print_t_name);
		pthread_mutex_lock(&phd->info->forks[phd->waf[RIGHT]]);
		mutex_wrap_writing(phd, TAKE_R_F, 23, print_t_name);
	}
}

void	forks_drop(t_philo *phd, int hand_1, int hand_2)
{
	pthread_mutex_unlock(&phd->info->forks[phd->waf[hand_1]]);
	pthread_mutex_unlock(&phd->info->forks[phd->waf[hand_2]]);
}
