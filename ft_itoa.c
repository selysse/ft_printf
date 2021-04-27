/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselyse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 21:14:32 by gselyse           #+#    #+#             */
/*   Updated: 2020/07/27 19:55:53 by gselyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_chk(long num, int base)
{
	size_t i;

	i = 0;
	while (num)
	{
		num = num / base;
		i++;
	}
	return (i);
}

static void		ft_min(long long int *num, int *minus, int base)
{
	if (*num < 0)
	{
		if (base == 10)
			*minus = 1;
		*num = *num * -1;
	}
}

static void		ft_convert(char *s, long long int num, int base, int len)
{
	char	*hex_base;
	int		i;

	i = 1;
	hex_base = "0123456789abcdef";
	while (num)
	{
		s[len - i++] = hex_base[num % base];
		num = num / base;
	}
	s[len] = '\0';
}

char			*ft_itoa(long long int num, int base)
{
	char	*str;
	int		len;
	int		minus;

	minus = 0;
	if (num == 0)
		return (ft_strdup("0"));
	if (base == 10 && num == -2147483648)
		return (ft_strdup("-2147483648"));
	ft_min(&num, &minus, base);
	len = ft_chk(num, base) + minus;
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (minus)
		str[0] = '-';
	ft_convert(str, num, base, len);
	return (str);
}
