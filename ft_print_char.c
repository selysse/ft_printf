/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselyse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 23:32:47 by gselyse           #+#    #+#             */
/*   Updated: 2020/07/27 19:45:46 by gselyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_char(t_lst *list_fl, va_list argv)
{
	char c;

	c = va_arg(argv, int);
	if ((list_fl->flag == -1 || list_fl->flag == 0) && \
	list_fl->width > 1)
		ft_putchar(' ', list_fl->width - 1, list_fl);
	ft_putchar(c, 1, list_fl);
	if (list_fl->flag == 1 && list_fl->width > 1)
		ft_putchar(' ', list_fl->width - 1, list_fl);
	ft_init(list_fl);
}
