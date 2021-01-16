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

void	lifecycle(t_philo *philo)
{
	if (philo->chg_able->name)
	while (!philo->death)
	{
		usleep(10000);

	}
}

int		thread_start(t_philo **philo, t_info *info)
{
	int		i;

	i = 0;
	while (i < info->rules[SUM_PH])
	{
		init_philo(philo, i, info);
		if (pthread_create(&philo[i]->th, NULL, (void *)lifecycle, &philo[i]))
			return (1);
		i++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_philo			*philo;
	t_info			info;

	if (philo_pars(argv, argc, &info))
		return (1);
	philo = malloc((info.rules[SUM_PH] - 1) * sizeof(t_philo));
	if (thread_start(&philo), &info)
		return (1);
}