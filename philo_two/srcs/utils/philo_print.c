/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:09:47 by gdougal           #+#    #+#             */
/*   Updated: 2021/01/21 17:09:48 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"
#include <unistd.h>

void	print_t_name(t_philo *phd, char *str, int n)
{
	if (phd->info->amdead || !phd->must_eat)
		return ;
	ft_putnbr_light(current_time(phd));
	write(1, " ", 1);
	ft_putnbr_light(phd->name);
	write(1, " ", 1);
	write(1, str, n);
}