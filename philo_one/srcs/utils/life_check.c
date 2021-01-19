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

void	life_check(t_philo **philo)
{
	t_philo	**phd;
	int		i;
	phd = philo;

	ssize_t curent;
	unsigned int delta;
	i = 0;
	while (1)
	{
		curent = time_start();
		delta = curent - (*phd)[i].last_eat;
		if ((*phd)[i].info->amdead)
			return;
		if (delta >= (ssize_t) (*phd)[i].info->rules[T_DIE])
			mutex_wrap_chng(&(*phd)[i], &(*phd)[i].info->l_check, &lol);
		i++;
		if (i == (*phd)[i].info->rules[SUM_PH])
			i = 0;
	}
}
