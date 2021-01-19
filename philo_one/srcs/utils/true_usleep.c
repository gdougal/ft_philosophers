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

void true_sleep(int wait, ssize_t cur)
{
	ssize_t	delta;

	delta = 0;
	while (delta <= wait)
	{
		usleep(10);
		delta = time_start() - cur;
	}
}