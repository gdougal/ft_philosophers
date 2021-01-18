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

#include "philo_one.h"

void	mutex_wrap_chng(t_philo *phd, pthread_mutex_t *type, void f_chng())
{
	pthread_mutex_lock(type);
	f_chng(phd);
	pthread_mutex_unlock(type);
}
