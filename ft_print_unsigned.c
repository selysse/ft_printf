/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselyse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 23:57:10 by gselyse           #+#    #+#             */
/*   Updated: 2020/07/27 19:59:12 by gselyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_unsigned(t_lst *list_fl, va_list argv)
{
	unsigned int	i;
	char			*s;

	if (!(i = va_arg(argv, unsigned int)))
		list_fl->zero = 1;
	if (!(s = ft_itoa(i, 10)))
		return (-1);
	if (list_fl->flag == 0 && list_fl->precision != -1)
		list_fl->flag = -1;
	if (list_fl->flag == -1 && list_fl->width > ft_strlen(s))
		ft_putchar(' ', ft_sp_num(ft_strlen(s), list_fl), list_fl);
	if (list_fl->flag == 0 && list_fl->width > ft_strlen(s))
		ft_putchar('0', list_fl->width - ft_strlen(s), list_fl);
	if (list_fl->precision != -1 && list_fl->precision > ft_strlen(s))
		ft_putchar('0', list_fl->precision - ft_strlen(s), list_fl);
	if (list_fl->precision || i)
		ft_putstr(s, list_fl);
	if (list_fl->flag == 1 && list_fl->width > ft_strlen(s))
		ft_putchar(' ', ft_sp_num(ft_strlen(s), list_fl), list_fl);
	ft_init(list_fl);
	free(s);
	return (0);
}
