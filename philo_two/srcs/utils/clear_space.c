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

#include "philo_two.h"

void	semaphore_close(t_info *info)
{
	if (info->forks != (sem_t *)-1)
		sem_close(info->forks);
	if (info->last_eat != (sem_t *)-1)
		sem_close(info->last_eat);
	if (info->start != (sem_t *)-1)
		sem_close(info->start);
	if (info->l_check != (sem_t *)-1)
		sem_close(info->l_check);
	if (info->write != (sem_t *)-1)
		sem_close(info->write);
	if (info->waiter != (sem_t *)-1)
		sem_close(info->waiter);
	semaphore_unlink();
}

void	clear_space(int status,  t_info *info, t_philo **phd)
{
	int	i;

	i = 0;
	if (status == 1 || status == 2)
		return ;
	if (status >= 3 || !status)
		free(*phd);
	if (status >= 4 || !status)
		pthread_join(info->d_th, NULL);
}
