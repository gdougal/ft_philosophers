/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 02:31:02 by gdougal           #+#    #+#             */
/*   Updated: 2021/01/19 02:31:04 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"


void	print_dead(t_philo *phd, char *str, int n)
{
	ft_putnbr_light(current_time(phd));
	write(1, " ", 1);
	ft_putnbr_light(phd->name);
	write(1, " ", 1);
	write(1, str, n);
}

void	dead_status(t_philo *phd)
{
	phd->info->amdead = phd->name;
	mutex_wrap_writing(phd, DEAD, 8, print_dead);
}

int status(t_info *info)
{
	int	status;
	pthread_mutex_lock(&info->chng);
	status = info->start;
	pthread_mutex_unlock(&info->chng);
	return (status);
}

void	life_check(t_philo **phd)
{
	int		i;
	ssize_t			delta;

	i = 0;
	while (status((*phd)->info) < (*phd)->info->rules[SUM_PH])
		usleep(10);
	while (1)
	{
		pthread_mutex_lock(&(*phd)->info->last_eat);
		delta = time_start() - (*phd)[i].last_eat;
		pthread_mutex_unlock(&(*phd)->info->last_eat);
		if (delta >= (*phd)[i].info->rules[T_DIE] && (*phd)[i].must_eat)
			mutex_wrap_chng(&(*phd)[i], &(*phd)[i].info->l_check, &dead_status);
		if (life_status(*phd) || !(*phd)[i].must_eat)
			break ;
		i++;
		if (i == (*phd)->info->rules[SUM_PH])
			i = 0;
		usleep(3000);
	}
}
