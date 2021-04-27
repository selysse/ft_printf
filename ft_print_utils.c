/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselyse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 20:10:07 by gselyse           #+#    #+#             */
/*   Updated: 2020/07/27 20:03:46 by gselyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_sp_num(int len, t_lst *list_fl)
{
	int space;

	if (list_fl->precision > len || (list_fl->precision == 0\
	&& list_fl->zero == 1))
	{
		space = list_fl->width - list_fl->precision;
		return (space);
	}
	space = list_fl->width - len;
	return (space);
}

int		ft_sp_str(int len, t_lst *list_fl)
{
	int space;

	if (list_fl->precision == -1 || list_fl->precision > len)
		space = list_fl->width - len;
	else
		space = list_fl->width - list_fl->precision;
	if (space > 0)
		return (space);
	return (0);
}

void	ft_flags_zero(char **s, t_lst *list_fl)
{
	if (list_fl->precision == -1)
		ft_print_minus(s, list_fl);
	if (list_fl->precision != -1)
		list_fl->flag = -1;
	if (list_fl->flag == 0 && list_fl->width > ft_strlen(*s))
		ft_putchar('0', list_fl->width - ft_strlen(*s), list_fl);
}

void	ft_flags_minus(char *s, t_lst *list_fl)
{
	if (list_fl->width > ft_strlen(s))
	{
		if (*s == '-' && list_fl->precision > ft_strlen(s))
			list_fl->width--;
		ft_putchar(' ', ft_sp_num(ft_strlen(s), list_fl), list_fl);
	}
}

void	ft_print_minus(char **s, t_lst *list_fl)
{
	if ((**s) == '-')
	{
		ft_putchar('-', 1, list_fl);
		(*s)++;
		list_fl->width--;
	}
}
