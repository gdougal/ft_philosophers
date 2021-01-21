/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 13:31:39 by gdougal           #+#    #+#             */
/*   Updated: 2021/01/17 13:31:42 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	every_day_the_same(t_philo *phd)
{
	forks_take(phd, RIGHT, LEFT);
	pthread_mutex_lock(&phd->info->last_eat);
	phd->last_eat = time_start();
	pthread_mutex_unlock(&phd->info->last_eat);
	mutex_wrap_writing(phd, EAT, 10, print_t_name);
	phd->must_eat--;
	true_sleep(phd->info->rules[T_EAT]);
	after_eat(phd);
	if (!phd->must_eat)
		return ;
	mutex_wrap_writing(phd, SLEEP, 12, print_t_name);
	true_sleep(phd->info->rules[T_SLEEP]);
	mutex_wrap_writing(phd, THINK, 12, print_t_name);
}