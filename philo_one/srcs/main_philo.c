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

void	change_status(t_info *info)
{
	pthread_mutex_lock(&info->chng);
	info->start++;
	pthread_mutex_unlock(&info->chng);
}

void	lifecycle(t_philo *phd)
{
	init_philo(phd);
	while (!life_status(phd) && phd->must_eat)
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
	if (info->rules[SUM_PH])
		while (i-- >= 0)
			pthread_join((*philo)[i].th, NULL);
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
		i++;
	}
}

int		main(int argc, char **argv)
{
	t_philo			*philo;
	t_info			info;

	if (philo_pars(argv, argc, &info))
		return (1);
	if (!(philo = (t_philo *)malloc((info.rules[SUM_PH]) * sizeof(t_philo))))
		return (1);
	pre_init(&philo, &info);
	if (thread_start(&philo, &info))
		return (1);
}