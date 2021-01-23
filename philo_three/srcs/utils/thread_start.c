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
#include <signal.h>


static void	forks_close(t_info *info, pid_t pid, pid_t *processes, int i)
{
	int	k;

	k = 0;
	if (pid)
	{
		if (pid < 0)
		{
			write(1, "Forks lol\n", 10);
			sem_post(info->start);
		}
		else if (pid > 0)
			sem_wait(info->detah);
		while (k < i)
		{
			kill(processes[k], SIGKILL);
			k++;
		}
	}
}

int			forks_start(t_philo *phd, t_info *info)
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
			if (pid < 0)
				break ;
			processes[i] = pid;
		}
		else
		{
			sem_wait(info->start);
			lifecycle(&phd[i]);
		}
		i++;
	}
	forks_close(info, pid, processes, i);
	semaphore_close(info);
	return (0);
}