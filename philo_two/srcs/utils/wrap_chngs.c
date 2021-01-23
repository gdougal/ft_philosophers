/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrap_chngs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 02:27:30 by gdougal           #+#    #+#             */
/*   Updated: 2021/01/19 02:27:32 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	sem_wrap_chng(t_philo *phd, sem_t *type, void f_chng())
{
	sem_wait(type);
	f_chng(phd);
	sem_post(type);
}
