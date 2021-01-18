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

void true_sleep(int wait)
{
	ssize_t			start;
	unsigned int	delta;

	delta = 0;
	start = time_start();
	while (delta <= wait)
		delta = time_start() - start;
}