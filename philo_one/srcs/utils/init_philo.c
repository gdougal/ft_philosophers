/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 14:15:32 by gdougal           #+#    #+#             */
/*   Updated: 2021/01/16 14:15:33 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	init_philo(t_philo *phd)
{
	phd->waf[LEFT] = phd->name - 1;
	phd->waf[RIGHT] = phd->name - 2;
	if (phd->waf[RIGHT] < 0)
		phd->waf[RIGHT] = phd->info->rules[SUM_PH] - 1;
	phd->t_start = time_start();
	phd->last_eat = current_time(phd);
	pthread_mutex_lock(&phd->info->chng);
	phd->info->start++;
	pthread_mutex_unlock(&phd->info->chng);
}