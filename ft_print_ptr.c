/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselyse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 16:26:09 by gselyse           #+#    #+#             */
/*   Updated: 2020/07/27 19:59:36 by gselyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_ptr(t_lst *list_fl, va_list argv)
{
	size_t	ptr;
	char	*str;

	if (!(ptr = va_arg(argv, size_t)))
		list_fl->zero = 1;
	if (!(str = ft_itoa(ptr, 16)))
		return (-1);
	if (list_fl->flag == 0 && list_fl->precision != -1)
		list_fl->flag = -1;
	if (list_fl->flag == -1 && list_fl->width > (ft_strlen(str) + 2))
		ft_putchar(' ', ft_sp_num(ft_strlen(str), list_fl) - 2, list_fl);
	ft_putstr("0x", list_fl);
	if (list_fl->precision != -1 && list_fl->precision > (ft_strlen(str)))
		ft_putchar('0', list_fl->precision - (ft_strlen(str)), list_fl);
	if (list_fl->flag == 0 && list_fl->width > (ft_strlen(str) + 2))
		ft_putchar('0', list_fl->width - (ft_strlen(str) + 2), list_fl);
	if (list_fl->precision || ptr)
		ft_putstr(str, list_fl);
	if (list_fl->flag == 1 && list_fl->width > (ft_strlen(str) + 2))
		ft_putchar(' ', ft_sp_num(ft_strlen(str), list_fl) - 2, list_fl);
	ft_init(list_fl);
	free(str);
	return (0);
}
