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

int data_mainer(t_philo *philo, char *argv, int i)
{
	philo->info[i] = ft_atoi(argv);
	if (philo->info[i] < 1)
		return (1);
	return (0);
}

int philo_pars(t_philo *philo, char **argv, int argc)
{
	int	i;
	int f;
	if (argc < 4 || argc > 5)
		return (1);
	if (argc < 5)
		philo->info[T_MST_E] = -1;
	i = 0;
	f = 0;
	while (argv[++i])
		f = data_mainer(philo, argv[i], i - 1);
	if (f != 0)
		return (1);
	philo->chg_able = malloc((philo->info[SUM_PH]) * sizeof(t_part_ph));
	return (0);
}

int main(int argc, char **argv)
{
	struct timeval	t_start;
	t_philo			philo;
	if (philo_pars(&philo, argv, argc))
		return (1);
	gettimeofday(&t_start, NULL);

}