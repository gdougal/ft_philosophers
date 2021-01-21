/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 23:46:11 by gdougal           #+#    #+#             */
/*   Updated: 2021/01/21 23:46:13 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"
#include <unistd.h>

void	print_dead(t_philo *phd, char *str, int n)
{
	ft_putnbr_light(current_time(phd));
	write(1, " ", 1);
	ft_putnbr_light(phd->name);
	write(1, " ", 1);
	write(1, str, n);
}
