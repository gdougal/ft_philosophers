/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_status.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 23:29:09 by gdougal           #+#    #+#             */
/*   Updated: 2021/01/21 23:29:11 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	change_status(t_info *info)
{
	pthread_mutex_lock(&info->chng);
	info->start++;
	pthread_mutex_unlock(&info->chng);
}
