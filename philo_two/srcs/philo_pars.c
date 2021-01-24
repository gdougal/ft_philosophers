/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_pars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 14:14:00 by gdougal           #+#    #+#             */
/*   Updated: 2021/01/16 14:14:03 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

static int		semaphore_init(t_info *info)
{
	info->amdead = 0;
	info->d_th = 0;
	sem_unlink("/forks");
	sem_unlink("/waiter");
	sem_unlink("/write");
	sem_unlink("/l_check");
	sem_unlink("/last_eat");
	sem_unlink("/start");
	info->forks = sem_open("/forks", O_CREAT, S_IRWXU, info->rules[SUM_PH]);
	info->waiter = sem_open("/waiter", O_CREAT, S_IRWXU, 1);
	info->write = sem_open("/write", O_CREAT, S_IRWXU, 1);
	info->l_check = sem_open("/l_check", O_CREAT, S_IRWXU, 1);
	info->last_eat = sem_open("/last_eat", O_CREAT, S_IRWXU, 1);
	info->start = sem_open("/start", O_CREAT, S_IRWXU, info->rules[SUM_PH]);
	return (0);
}

static int		data_mainer(t_info *info, char *argv, int i)
{
	info->rules[i] = ft_atoi(argv);
	if (info->rules[i] < 1)
		return (2);
	return (0);
}

int				philo_pars(char **argv, int argc, t_info *info)
{
	int	i;
	int	status;

	if (argc < 5 || argc > 6)
		return (1);
	if (argc == 6)
		info->rules[T_MST_E] = -1;
	i = 0;
	while (argv[++i])
		status = data_mainer(info, argv[i], i - 1);
	if (status)
		return (status);
	if ((status = semaphore_init(info)))
		return (status);
	return (0);
}
