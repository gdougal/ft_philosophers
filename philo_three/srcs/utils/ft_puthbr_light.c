/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 13:49:35 by gdougal           #+#    #+#             */
/*   Updated: 2021/01/17 13:49:36 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"
#include <unistd.h>

void	ft_putnbr_light(unsigned int n)
{
	char			num;
	unsigned int	i;
	unsigned int	j;

	i = n;
	j = 10;
	while (i /= 10)
		j *= 10;
	while (j /= 10)
	{
		num = (n / j) + '0';
		write(1, &num, 1);
		n %= j;
	}
}