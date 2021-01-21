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
	if (life_status(phd) || !phd->must_eat)
		return ;
	ft_putnbr_light(current_time(phd));
	write(1, " ", 1);
	ft_putnbr_light(phd->name);
	write(1, " ", 1);
	write(1, str, n);
}

void	every_day_the_same(t_philo *phd)
{
	before_eat(phd);

	pthread_mutex_lock(&phd->info->last_eat);
	phd->last_eat = time_start();
	pthread_mutex_unlock(&phd->info->last_eat);

	mutex_wrap_writing(phd, EAT, 10, print_t_name);
	phd->must_eat--;
	true_sleep(phd->info->rules[T_EAT], current_time(phd), phd);

	after_eat(phd);

	if (!phd->must_eat)
		return ;
	mutex_wrap_writing(phd, SLEEP, 12, print_t_name);
	true_sleep(phd->info->rules[T_SLEEP], current_time(phd), phd);
	mutex_wrap_writing(phd, THINK, 12, print_t_name);
}