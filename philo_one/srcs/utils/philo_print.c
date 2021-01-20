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


int		life_status(t_philo *phd)
{
	int	k;
	pthread_mutex_lock(&phd->info->l_check);
	k = phd->info->amdead;
	pthread_mutex_unlock(&phd->info->l_check);
	return (k);
}

void	print_t_name(t_philo *phd, char *str, int n)
{
	if (life_status(phd))
		return ;
	ft_putnbr_light(current_time(phd));
	write(1, " ", 1);
	ft_putnbr_light(phd->name);
	write(1, " ", 1);
	write(1, str, n);
}

void	some_bussines(t_philo *phd, char *str, int n, int type)
{
	if (life_status(phd))
		return ;
	if (type == T_EAT && !phd->info->amdead)
		forks_take(phd);
	mutex_wrap_writing(phd, str, n, print_t_name);
	if (type == T_EAT || type == T_SLEEP)
	{
		if (type == T_EAT)
		{
			pthread_mutex_lock(&phd->info->last_eat);
			phd->last_eat = current_time(phd);
			pthread_mutex_unlock(&phd->info->last_eat);
		}
		true_sleep(phd->info->rules[type], current_time(phd), phd);
		if (type == T_EAT)
			if_eat(phd);
	}
}

int		every_day_the_same(t_philo *phd)
{
	some_bussines(phd, EAT, 10, T_EAT);
	some_bussines(phd, SLEEP, 12, T_SLEEP);
	some_bussines(phd, THINK, 12, 0);
	if(life_status(phd))
		return (1);
	return (0);
}