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

static int	forks_close(t_info *info, pid_t pid, pid_t *processes, int i)
{
	int		k;

	k = 0;
	if (i == info->rules[SUM_PH])
		while (k < i)
		{
			sem_post(info->start);
			k++;
		}
	k = 0;
	if (pid)
	{
		if (pid < 0)
			write(1, "Forks lol\n", 10);
		else if (pid > 0)
			sem_wait(info->detah);
		while (k < i)
		{
			kill(processes[k], SIGKILL);
			k++;
		}
	}
	return (k);
}

int			forks_start(t_philo *phd, t_info *info, pid_t **processes)
{
	int		i;
	pid_t	pid;

	i = 0;
	while (i < info->rules[SUM_PH])
	{
		pid = fork();
		if (pid < 0)
			break ;
		if (pid)
			(*processes)[i] = pid;
		else
		{
			sem_wait(info->start);
			lifecycle(&phd[i]);
		}
		i++;
	}
	if (forks_close(info, pid, *processes, i) != i)
		return (6);
	semaphore_close(info);
	return (0);
}
