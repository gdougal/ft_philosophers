/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 23:34:51 by gdougal           #+#    #+#             */
/*   Updated: 2021/01/21 23:34:53 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

int		thread_start(t_philo *phd, t_info *info)
{
	int	i;
	pid_t	pid;
	pid_t	*processes;


	i = 0;
	processes = malloc(sizeof(pid_t) * info->rules[SUM_PH]);
	sem_wait(phd->info->detah);
	while (i < info->rules[SUM_PH])
	{
		pid = fork();
		if (pid)
		{
			processes[i] = pid;
			phd[i].proc = pid;
		}
		else
			lifecycle(&phd[i]);
		i++;
	}
	i = 0;
	if (pid)
	{
		sem_wait(phd->info->detah);
		while (i < info->rules[SUM_PH])
		{
			kill(processes[i], SIGKILL);
			i++;
		}
	}
	wait(NULL);
	i = 0;
	semaphore_close(info);
	return (0);
}