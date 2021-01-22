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

#include "philo_two.h"

void	dead_status(t_philo *phd)
{
	phd->info->amdead = phd->name;
	sem_wrap_writing(phd, DEAD, 8, print_dead);
}