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
	if (type == T_EAT)
		forks_take(phd);
	mutex_wrap_writing(phd, str, n, print_t_name);
	true_sleep(phd->info->rules[type], current_time(phd), phd);
}

int		every_day_the_same(t_philo *phd)
{
	some_bussines(phd, EAT, 10, T_EAT);
	if_eat(phd);
	some_bussines(phd, SLEEP, 12, T_SLEEP);
	mutex_wrap_writing(phd, THINK, 12, print_t_name);
	if(life_status(phd))
		return (1);
	return (0);
}