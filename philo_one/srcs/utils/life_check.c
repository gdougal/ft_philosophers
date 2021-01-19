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

void	lol(t_philo *phd)
{
	phd->info->amdead = phd->name;
}

void	life_check(t_philo **phd)
{
	int		i;

	unsigned int delta;
	unsigned int cur;
	i = 0;
	while ((*phd)->info->start != 2);
	while (1)
	{
		cur = current_time(&(*phd)[i]);
		pthread_mutex_lock(&(*phd)->info->last_eat);
		delta = cur - (*phd)[i].last_eat;
		pthread_mutex_unlock(&(*phd)->info->last_eat);
		if (delta >= (ssize_t) (*phd)[i].info->rules[T_DIE])
			mutex_wrap_chng(&(*phd)[i], &(*phd)[i].info->l_check, &lol);
		i++;
		if (i == (*phd)->info->rules[SUM_PH])
			i = 0;
		if ((*phd)[i].info->amdead)
			break ;
	}
}
