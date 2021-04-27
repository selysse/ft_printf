/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_parc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselyse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 02:41:04 by gselyse           #+#    #+#             */
/*   Updated: 2020/07/27 20:04:32 by gselyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parflags(t_lst *list_fl, const char **str)
{
	while (*(*str + 1) == '-' || *(*str + 1) == '0')
	{
		if (*(*str + 1) == '-')
			list_fl->flag = 1;
		if (*(*str + 1) == '0' && list_fl->flag != 1)
			list_fl->flag = 0;
		(*str)++;
	}
}

void	ft_parwidth(t_lst *list_fl, const char **str, va_list argv)
{
	if (ft_isdigit(*(*str + 1)))
	{
		list_fl->width = ft_atoi(*str + 1);
		while (ft_isdigit(*(*str + 1)))
			(*str)++;
	}
	else if (*(*str + 1) == '*')
	{
		list_fl->width = va_arg(argv, int);
		if (list_fl->width < 0)
		{
			list_fl->width = list_fl->width * -1;
			list_fl->flag = 1;
		}
		(*str)++;
	}
}

void	ft_parprec(t_lst *list_fl, const char **str, va_list argv)
{
	if (*(*str + 1) == '.')
	{
		list_fl->precision = 0;
		(*str)++;
		if (ft_isdigit(*(*str + 1)))
		{
			list_fl->precision = ft_atoi(*str + 1);
			while (ft_isdigit(*(*str + 1)))
				(*str)++;
		}
		else if (*(*str + 1) == '*')
		{
			list_fl->precision = va_arg(argv, int);
			(*str)++;
		}
	}
	if (list_fl->precision < 0)
		list_fl->precision = -1;
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*dst;

	i = ft_strlen(s) + 1;
	if (!(dst = (char *)malloc(sizeof(char) * i)))
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
