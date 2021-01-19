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
	ssize_t	start;
	int		lol;
	int		kek;
	if (!phd->last_eat)
		return ;
	start = time_start();
	lol = phd->info->rules[T_DIE];
	kek = (int)(start - phd->last_eat);
	if (kek >= lol)
		phd->info->amdead = phd->name;
}
