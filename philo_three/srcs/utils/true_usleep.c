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

#include "philo_three.h"
#include <unistd.h>

void		true_sleep(int wait)
{
	ssize_t	start;

	start = time_start();
	while (time_start() - start < wait)
		usleep(1);
}
