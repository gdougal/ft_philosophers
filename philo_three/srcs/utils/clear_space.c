/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 23:33:14 by gdougal           #+#    #+#             */
/*   Updated: 2021/01/21 23:33:15 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	semaphore_close(t_info *info)
{
	if (info->forks != (sem_t *)-1)
		sem_close(info->forks);
	if (info->waiter != (sem_t *)-1)
		sem_close(info->waiter);
	if (info->write != (sem_t *)-1)
		sem_close(info->write);
	if (info->must_eat != (sem_t *)-1)
		sem_close(info->must_eat);
	if (info->last_eat != (sem_t *)-1)
		sem_close(info->last_eat);
	if (info->detah != (sem_t *)-1)
		sem_close(info->detah);
	if (info->start != (sem_t *)-1)
		sem_close(info->start);
	if (info->first != (sem_t *)-1)
		sem_close(info->first);
	semaphore_unlink();
}

void	clear_space(int status, t_philo **phd, pid_t **processes)
{
	if (status == 1 || status == 2 || status == 3)
		return ;
	if (status >= 4 || !status)
		free(*phd);
	if (status >= 5 || !status)
		free(*processes);
}
