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

#include "philo_one.h"
#include <unistd.h>

void	lifecycle(t_philo *phd)
{
	init_philo(phd);
	change_status(phd->info);
	while (start_status(phd->info) < phd->info->rules[SUM_PH])
		usleep(10);
	while (!phd->info->amdead && phd->must_eat)
		every_day_the_same(phd);
}
