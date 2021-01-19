/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   true_usleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 11:17:05 by gdougal           #+#    #+#             */
/*   Updated: 2021/01/18 11:17:07 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void true_sleep(int wait, ssize_t cur, t_philo *phd)
{
	ssize_t	delta;

	delta = 0;
	while (delta != wait)
	{
		usleep(500);
		delta = current_time(phd) - cur;
//		if (phd->info->amdead)
//			return ;
	}
}