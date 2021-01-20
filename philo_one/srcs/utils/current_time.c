/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   current_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 21:35:41 by gdougal           #+#    #+#             */
/*   Updated: 2021/01/15 21:35:43 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

ssize_t		current_time(t_philo *philo)
{
	struct timeval	t_cur;
	gettimeofday(&t_cur, NULL);
	philo->curent_time = (ssize_t)(t_cur.tv_sec * 1000 + t_cur.tv_usec / 1000) - philo->t_start;
	return (philo->curent_time);
}