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
	if (phd->name % 2)
		forks_drop(phd, RIGHT, LEFT);
	else
		forks_drop(phd, LEFT, RIGHT);
}
