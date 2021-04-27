/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselyse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 17:21:28 by gselyse           #+#    #+#             */
/*   Updated: 2020/07/27 20:38:26 by gselyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_skip(const char *nptr, int *min)
{
	int i;

	i = 0;
	while (nptr[i] == '\n' || nptr[i] == '\r' || nptr[i] == '\f' || \
	nptr[i] == '\v' || nptr[i] == '\t' || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			*min = -1;
		i++;
	}
	return (i);
}

int			ft_atoi(const char *nptr)
{
	int				i;
	int				min;
	unsigned long	res;

	min = 1;
	res = 0;
	i = ft_skip(nptr, &min);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - '0');
		if (!(ft_isdigit(nptr[i + 1])))
		{
			if (res > LONG_MAX - 1 && min == -1)
				return (0);
			if (res > LONG_MAX && min == 1)
				return (-1);
			return (res * min);
		}
		i++;
	}
	return (0);
}
