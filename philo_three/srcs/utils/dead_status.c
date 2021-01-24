/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 23:44:53 by gdougal           #+#    #+#             */
/*   Updated: 2021/01/21 23:44:54 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	dead_status(t_philo *phd)
{
	phd->info->amdead = phd->name;
	sem_wait(phd->info->write);
	print_dead(phd, DEAD, 8);
	sem_post(phd->info->detah);
}
