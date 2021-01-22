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

#include "philo_two.h"

void	sem_wrap_writing(t_philo *phd, char * str, int n, void f_write())
{
	sem_wait(phd->info->write);
	f_write(phd, str, n);
	sem_post(phd->info->write);
}
