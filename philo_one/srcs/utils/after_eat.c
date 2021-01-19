/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   after_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 02:33:09 by gdougal           #+#    #+#             */
/*   Updated: 2021/01/19 02:33:11 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	if_eat(t_philo *phd)
{
	phd->last_eat = time_start();
	if (phd->name % 2)
		right_forks_drop(phd);
	else
		left_forks_drop(phd);
}
