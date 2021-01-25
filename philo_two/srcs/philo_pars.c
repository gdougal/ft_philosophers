/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_pars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 14:14:00 by gdougal           #+#    #+#             */
/*   Updated: 2021/01/25 15:08:18 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void			semaphore_unlink(void)
{
	sem_unlink("/forks");
	sem_unlink("/waiter");
	sem_unlink("/write");
	sem_unlink("/l_check");
	sem_unlink("/last_eat");
	sem_unlink("/start");
}

static int		semaphore_init(t_info *info)
{
	info->amdead = 0;
	info->d_th = 0;
	semaphore_unlink();
	info->forks = sem_open("/forks", O_CREAT, S_IRWXU, info->rules[SUM_PH]);
	info->waiter = sem_open("/waiter", O_CREAT, S_IRWXU, 1);
	info->write = sem_open("/write", O_CREAT, S_IRWXU, 1);
	info->l_check = sem_open("/l_check", O_CREAT, S_IRWXU, 1);
	info->last_eat = sem_open("/last_eat", O_CREAT, S_IRWXU, 1);
	info->start = sem_open("/start", O_CREAT, S_IRWXU, info->rules[SUM_PH]);
	if (info->forks == (sem_t *)-1 || info->waiter == (sem_t *)-1 ||
	info->write == (sem_t *)-1 || info->l_check == (sem_t *)-1 ||
	info->last_eat == (sem_t *)-1 || info->start == (sem_t *)-1)
		return (-1);
	return (0);
}

static int		data_mainer(t_info *info, char *argv, int i)
{
	info->rules[i] = ft_atoi(argv);
	if (info->rules[i] < 2)
		return (2);
	return (0);
}

int				philo_pars(char **argv, int argc, t_info *info)
{
	int	i;
	int	status;

	if (argc < 5 || argc > 6)
		return (1);
	info->rules[T_MST_E] = -1;
	i = 0;
	while (argv[++i])
	{
		status = data_mainer(info, argv[i], i - 1);
		if (status)
			return (status);
	}
	if (semaphore_init(info))
	{
		semaphore_close(info);
		status = 2;
		return (status);
	}
	return (0);
}
