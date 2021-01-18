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

void	lifecycle(t_philo *phd)
{
	init_philo(phd);
	while (!every_day_the_same(phd));
	if (phd->info->amdead && phd->info->amdead == phd->name)
		some_bussines(phd, "is dead\n", 8, 0);
}

int		thread_start(t_philo **philo, t_info *info)
{
	int		i;
	int		k;

	i = 0;
	while (i < info->rules[SUM_PH])
	{
		(*philo)[i].name = i + 1;
		(*philo)[i].info = info;
		if (pthread_create(&(*philo)[i].th, NULL, (void *)lifecycle, &(*philo)[i]))
			return (1);
		i++;
	}
	k = info->amdead - 1;
	pthread_join((*philo)[k].th, NULL);
	while (i-- >= 0)
		if (i != k)
			pthread_join((*philo)[i].th, NULL);
	return (0);
}

int		main(int argc, char **argv)
{
	t_philo			*philo;
	t_info			info;

	if (philo_pars(argv, argc, &info))
		return (1);
	philo = (t_philo * )malloc((info.rules[SUM_PH]) * sizeof(t_philo));
	if (thread_start(&philo, &info))
		return (1);
}