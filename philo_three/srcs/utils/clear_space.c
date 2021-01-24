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
	sem_close(info->forks);
	sem_close(info->waiter);
	sem_close(info->write);
	sem_close(info->last_eat);
	sem_close(info->detah);
	sem_close(info->start);
	sem_close(info->must_eat);
	sem_unlink("/forks");
	sem_unlink("/waiter");
	sem_unlink("/write");
	sem_unlink("/last_eat");
	sem_unlink("/death");
	sem_unlink("/start");
	sem_unlink("/must_eat");
}

void	clear_space(int status, t_philo **phd, pid_t **processes)
{
	if (status == 1 || status == 2 || status == 3)
		return ;
	if (status >= 4)
		free(*phd);
	if (status >= 5)
		free(*processes);
}
