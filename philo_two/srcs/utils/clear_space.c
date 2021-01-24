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
	sem_close(info->forks);
	sem_close(info->last_eat);
	sem_close(info->start);
	sem_close(info->l_check);
	sem_close(info->write);
	sem_close(info->waiter);
	sem_unlink("/forks");
	sem_unlink("/waiter");
	sem_unlink("/write");
	sem_unlink("/l_check");
	sem_unlink("/last_eat");
	sem_unlink("/start");
}

void	clear_space(int status,  t_info *info, t_philo **phd)
{
	int	i;

	i = 0;
	if (status == 1 || status == 2)
		return ;
	if (status >= 3)
		free(*phd);
	if (status >= 4)
		while(i < info->rules[SUM_PH])
		{
			if ((*phd)[i].th)
				pthread_join((*phd)[i].th, NULL);
			i++;
		}
}
