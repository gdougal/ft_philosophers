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
	current_time(phd);
	phd->last_eat = 0;
}