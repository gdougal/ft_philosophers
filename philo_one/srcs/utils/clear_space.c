/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 23:33:14 by gdougal           #+#    #+#             */
/*   Updated: 2021/01/21 23:33:15 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	clear_space(int status, t_info *info, t_philo **phd)
{
	if (status == 1 || status == 2 || status == 3)
		return ;
	if (status >= 5)
		free(info->forks);
	if (status >= 6)
		free(*phd);
}
