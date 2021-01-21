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

#include "philo_one.h"

int				forks_init(t_info *info)
{
	int	i;

	i = 0;
	info->forks = malloc((info->rules[SUM_PH]) * sizeof(pthread_mutex_t));
	while (i < info->rules[SUM_PH])
	{
		if (pthread_mutex_init(&info->forks[i], NULL))
			return (1);
		i++;
	}
	pthread_mutex_init(&info->write, NULL);
	pthread_mutex_init(&info->l_check, NULL);
	pthread_mutex_init(&info->last_eat, NULL);
	pthread_mutex_init(&info->chng, NULL);
	pthread_mutex_init(&info->fork, NULL);
	info->start = 0;
	return (0);
}

static int		data_mainer(t_info *info, char *argv, int i)
{
	info->rules[i] = ft_atoi(argv);
	if (info->rules[i] < 1)
		return (1);
	return (0);
}

int		philo_pars(char **argv, int argc, t_info *info)
{
	int	i;
	int f;
	if (argc < 5 || argc > 6)
		return (1);
	if (argc == 6)
		info->rules[T_MST_E] = -1;
	i = 0;
	f = 0;
	while (argv[++i])
		f = data_mainer(info, argv[i], i - 1);
	if (f != 0)
		return (1);
	if (forks_init(info))
		return (1);
	info->amdead = 0;
	return (0);
}