/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 15:19:25 by gdougal           #+#    #+#             */
/*   Updated: 2021/01/15 15:19:27 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"
#include <unistd.h>

void	change_status(t_info *info)
{
	pthread_mutex_lock(&info->chng);
	info->start++;
	pthread_mutex_unlock(&info->chng);
}

void	lifecycle(t_philo *phd)
{
	init_philo(phd);
	change_status(phd->info);
	while (status(phd->info) < phd->info->rules[SUM_PH]);
//	if ((phd->name % 2))
//		usleep(500);
	while (!phd->info->amdead && phd->must_eat)
		every_day_the_same(phd);
}

int		thread_start(t_philo **philo, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->rules[SUM_PH])
	{
		if (pthread_create(&(*philo)[i].th, NULL, (void *)lifecycle, &(*philo)[i]))
			return (1);
		i++;
	}
	if (pthread_create(&info->d_th, NULL, (void *)life_check, philo))
		return (1);
	pthread_join(info->d_th, NULL);
	while (i-- >= 0)
		pthread_join((*philo)[i].th, NULL);
	return (0);
}

void	pre_init(t_philo **phd, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->rules[SUM_PH])
	{
		(*phd)[i].info = info;
		(*phd)[i].name = i + 1;
		(*phd)[i].t_start = 0;
		(*phd)[i].curent_time = 0;
		(*phd)[i].last_eat = 0;
		(*phd)[i].last_eat = 0;
		(*phd)[i].waf[LEFT] = (*phd)[i].name - 1;
		(*phd)[i].waf[RIGHT] = (*phd)[i].name - 2;
		if ((*phd)[i].waf[RIGHT] < 0)
			(*phd)[i].waf[RIGHT] = info->rules[SUM_PH] - 1;
		(*phd)[i].must_eat = (*phd)[i].info->rules[T_MST_E];
		pthread_mutex_init(&(*phd)[i].cheel, NULL);
		i++;
	}
}

void clear_space(int status, t_info *info, t_philo **phd)
{
	if (status == 1 || status == 2 || status == 3)
		return ;
	if (status >= 5)
		free(info->forks);
	if (status >= 6)
		free(*phd);
}

int		main(int argc, char **argv)
{
	t_philo			*philo;
	t_info			info;
	int				status;

	status = 0;
	status = philo_pars(argv, argc, &info);
	if (!status)
		if (!(philo = (t_philo *)malloc((info.rules[SUM_PH]) * sizeof(t_philo))))
			status = 5;
	if (!status)
	{
		pre_init(&philo, &info);
		if (thread_start(&philo, &info))
			status = 6;
	}
	clear_space(status, &info, &philo);
	return (status);
}