/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 23:34:51 by gdougal           #+#    #+#             */
/*   Updated: 2021/01/21 23:34:53 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"
#include <unistd.h>

int		thread_start(t_philo **philo, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->rules[SUM_PH])
	{
		sem_wait(info->start);
		if (pthread_create(&(*philo)[i].th,
					NULL, (void *)lifecycle, &(*philo)[i]))
			return (1);
		i++;
	}
	if (!info->amdead)
		if (pthread_create(&info->d_th, NULL, (void *) life_check, philo))
			return (1);
	pthread_join(info->d_th, NULL);
	while (i-- >= 0)
		pthread_join((*philo)[i].th, NULL);
	semaphore_close(info);
	return (0);
}
