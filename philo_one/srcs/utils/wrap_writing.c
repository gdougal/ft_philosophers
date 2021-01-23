/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrap_writing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 02:28:30 by gdougal           #+#    #+#             */
/*   Updated: 2021/01/19 02:28:31 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	mutex_wrap_writing(t_philo *phd, char *str, int n, void f_write())
{
	pthread_mutex_lock(&phd->info->write);
	f_write(phd, str, n);
	pthread_mutex_unlock(&phd->info->write);
}
