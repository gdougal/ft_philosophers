/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_take_and_drop.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 02:29:51 by gdougal           #+#    #+#             */
/*   Updated: 2021/01/19 02:29:53 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"
#include <pthread.h>

void	forks_take(t_philo *phd)
{
	sem_wait(phd->info->waiter);
	sem_wait(phd->info->forks);
	sem_wrap_writing(phd, TAKE_F, 17, print_t_name);
	sem_wait(phd->info->forks);
	sem_wrap_writing(phd, TAKE_F, 17, print_t_name);
	sem_post(phd->info->waiter);
}

void	forks_drop(t_philo *phd)
{
	sem_post(phd->info->forks);
	sem_post(phd->info->forks);
}
