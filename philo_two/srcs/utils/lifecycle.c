/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lifesycle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 23:30:45 by gdougal           #+#    #+#             */
/*   Updated: 2021/01/21 23:30:46 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	lifecycle(t_philo *phd)
{
	init_philo(phd);
	sem_post(phd->info->start);
	while (!phd->info->amdead && phd->must_eat)
		every_day_the_same(phd);
	sem_post(phd->info->start);
}
