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

#include "philo_three.h"
#include <unistd.h>

void	life_check(t_philo *phd)
{
	ssize_t		delta;

	while (1)
	{
		sem_wait(phd->info->last_eat);
		delta = time_start() - phd->last_eat;
		sem_post(phd->info->last_eat);
		if (delta >= phd->info->rules[T_DIE] && phd->must_eat)
			sem_wrap_chng(phd, phd->info->l_check, &dead_status);
		if (phd->info->amdead)
			return ;
		usleep(1);
	}
}