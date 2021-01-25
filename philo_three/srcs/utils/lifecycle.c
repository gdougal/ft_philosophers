/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lifesycle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 23:30:45 by gdougal           #+#    #+#             */
/*   Updated: 2021/01/24 22:18:56 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"
#include <signal.h>
#include <unistd.h>

void	lifecycle(t_philo *phd)
{
	int	i;

	i = phd->info->rules[SUM_PH];
	init_philo(phd);
	if (pthread_create(&phd->th, NULL, (void *)life_check, phd))
	{
		sem_wait(phd->info->write);
		write(1, "Threads lol\n", 10);
		sem_post(phd->info->detah);
	}
	if (phd->info->amdead)
	{
		pthread_join(phd->th, 0);
		return ;
	}
	if (phd->must_eat != 0)
		while (!every_day_the_same(phd))
			;
	sem_wait(phd->info->first);
	while (i--)
		sem_wait(phd->info->must_eat);
	sem_post(phd->info->detah);
	exit(0);
}
