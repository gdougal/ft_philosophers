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
	ft_putnbr_light(current_time(phd));
	write(1, " ", 1);
	ft_putnbr_light(phd->name);
	write(1, " ", 1);
	write(1, str, n);
}

void	some_bussines(t_philo *phd, char *str, int n, int type)
{
	mutex_wrap_writing(phd, str, n, print_t_name);
	if (type == T_EAT || type == T_SLEEP)
	{
		if (type == T_EAT)
		{
			pthread_mutex_lock(&phd->info->chngs);
			phd->last_eat = current_time(phd);
			pthread_mutex_unlock(&phd->info->chngs);
			if (phd->name % 2)
				right_forks_drop(phd);
			else
				left_forks_drop(phd);
		}
		usleep(phd->info->rules[type] / 1000);
	}
}

int		every_day_the_same(t_philo *phd)
{
	forks_take(phd);
	some_bussines(phd, "is eating\n", 10, T_EAT);
	some_bussines(phd, "is sleeping\n", 12, T_SLEEP);
	some_bussines(phd, "is thinking\n", 12, 0);
	return (0);
}