/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 21:44:05 by gdougal           #+#    #+#             */
/*   Updated: 2021/01/15 21:44:06 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_atoi(const char *nptr)
{
	int		sign;
	int		i;
	long	num;

	num = 0;
	sign = 1;
	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\n' || nptr[i] == '\t'
		|| nptr[i] == '\r' || nptr[i] == '\v' || nptr[i] == '\f')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		sign = (nptr[i++] == '-' ? -1 : +1);
	while (nptr[i] == '0')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (num > ((num * 10) + nptr[i] - 48))
			return (sign > 0 ? -1 : 0);
		num = (num * 10) + nptr[i++] - 48;
	}
	return (sign * (int)num);
}
