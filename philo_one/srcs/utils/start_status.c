/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 23:42:56 by gdougal           #+#    #+#             */
/*   Updated: 2021/01/21 23:42:58 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		start_status(t_info *info)
{
	int	status;

	pthread_mutex_lock(&info->chng);
	status = info->start;
	pthread_mutex_unlock(&info->chng);
	return (status);
}
