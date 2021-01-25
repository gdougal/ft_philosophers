/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_pars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 14:14:00 by gdougal           #+#    #+#             */
/*   Updated: 2021/01/25 15:08:44 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int				forks_init(t_info *info)
{
	int	i;
	int k;

	i = 0;
	k = 0;
	info->amdead = 0;
	info->d_th = 0;
	if (!(info->forks =
		malloc((info->rules[SUM_PH]) * sizeof(pthread_mutex_t))))
		return (3);
	while (i < info->rules[SUM_PH])
	{
		if ((k += pthread_mutex_init(&info->forks[i], NULL)))
			return (4);
		i++;
	}
	k += pthread_mutex_init(&info->write, NULL);
	k += pthread_mutex_init(&info->l_check, NULL);
	k += pthread_mutex_init(&info->last_eat, NULL);
	k += pthread_mutex_init(&info->chng, NULL);
	if (k)
		return (4);
	info->start = 0;
	return (0);
}

static int		data_mainer(t_info *info, char *argv, int i)
{
	info->rules[i] = ft_atoi(argv);
	if (info->rules[i] < 2)
		return (2);
	return (0);
}

int				philo_pars(char **argv, t_info *info)
{
	int	i;
	int	status;

	info->rules[T_MST_E] = -1;
	i = 0;
	while (argv[++i])
	{
		status = data_mainer(info, argv[i], i - 1);
		if (status)
			return (status);
	}
	if ((status = forks_init(info)))
		return (status);
	return (0);
}
