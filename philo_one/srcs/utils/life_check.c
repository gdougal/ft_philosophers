/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 02:31:02 by gdougal           #+#    #+#             */
/*   Updated: 2021/01/19 02:31:04 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	life_check(t_philo *phd)
{
	if (current_time(phd) - phd->last_eat >= phd->info->rules[T_DIE])
		phd->info->amdead = phd->name;
}
