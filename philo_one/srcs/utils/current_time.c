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

long int current_time(t_philo *philo)
{
	long int	cur_t;
	struct timeval t_cur;
	gettimeofday(&t_cur, NULL);
	cur_t = (t_cur.tv_sec * 1000 + t_cur.tv_usec / 1000) - philo->chg_able->t_start;
//	philo->chg_able->t_start = (t_start.tv_sec * 1000 + t_start.tv_usec / 1000); philo.t_start
	return (cur_t);
}