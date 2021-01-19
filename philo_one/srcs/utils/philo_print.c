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


void	print_t_name(t_philo *phd, char *str, int n)
{
	if (phd->info->amdead && phd->info->amdead != phd->name)
		return ;
	ft_putnbr_light(current_time(phd));
	write(1, " ", 1);
	ft_putnbr_light(phd->name);
	write(1, " ", 1);
	write(1, str, n);
}

void	some_bussines(t_philo *phd, char *str, int n, int type)
{
	if (phd->info->amdead && phd->info->amdead != phd->name)
		return ;
	if (type == T_EAT && !phd->info->amdead)
	{
		forks_take(phd);
		pthread_mutex_lock(&phd->info->last_eat);
		phd->last_eat = current_time(phd);
		pthread_mutex_unlock(&phd->info->last_eat);
	}
	mutex_wrap_writing(phd, str, n, print_t_name);
	if (type == T_EAT || type == T_SLEEP)
	{
		true_sleep(phd->info->rules[type], current_time(phd), phd);
		if (type == T_EAT)
			if_eat(phd);
	}
}

int		every_day_the_same(t_philo *phd)
{
	if (phd->info->amdead)
		return (1);
	some_bussines(phd, "is eating\n", 10, T_EAT);
	if (phd->info->amdead)
		return (1);
	some_bussines(phd, "is sleeping\n", 12, T_SLEEP);
	if (phd->info->amdead)
		return (1);
	some_bussines(phd, "is thinking\n", 12, 0);
	if (phd->info->amdead)
		return (1);
	return (0);
}