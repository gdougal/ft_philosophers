/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 14:12:28 by gdougal           #+#    #+#             */
/*   Updated: 2021/01/16 14:12:29 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

ssize_t 	time_start(void)
{
	ssize_t	s_time;
	struct timeval	t_start;
	gettimeofday(&t_start, NULL);
	s_time = (ssize_t)((double)t_start.tv_sec * 1000 + t_start.tv_usec * 0.001);
	return (s_time);
}