/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselyse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 23:56:29 by gselyse           #+#    #+#             */
/*   Updated: 2020/07/27 20:39:04 by gselyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(t_lst *list_fl, va_list argv)
{
	int		num;
	char	*s;
	char	*tmp;

	if (!(num = va_arg(argv, int)))
		list_fl->zero = 1;
	if (!(tmp = ft_itoa(num, 10)))
		return (-1);
	s = tmp;
	if (list_fl->flag == 0)
		ft_flags_zero(&s, list_fl);
	if (list_fl->flag == -1)
		ft_flags_minus(s, list_fl);
	if (list_fl->precision != -1 && list_fl->precision > ft_strlen(s))
	{
		ft_print_minus(&s, list_fl);
		ft_putchar('0', list_fl->precision - ft_strlen(s), list_fl);
	}
	if (list_fl->precision || num)
		ft_putstr(s, list_fl);
	if (list_fl->flag == 1 && list_fl->width > ft_strlen(s))
		ft_putchar(' ', ft_sp_num(ft_strlen(s), list_fl), list_fl);
	ft_init(list_fl);
	free(tmp);
	return (0);
}
