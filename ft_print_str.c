/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselyse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 23:57:00 by gselyse           #+#    #+#             */
/*   Updated: 2020/07/27 20:00:24 by gselyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_str(t_lst *list_fl, va_list argv)
{
	char *s;

	s = va_arg(argv, char *);
	if (!s)
		s = "(null)";
	if (list_fl->flag == -1)
		ft_putchar(' ', ft_sp_str(ft_strlen(s), list_fl), list_fl);
	if (list_fl->flag == 0 && list_fl->width > ft_strlen(s))
		ft_putchar('0', list_fl->width - ft_strlen(s), list_fl);
	ft_putstr(s, list_fl);
	if (list_fl->flag == 1)
		ft_putchar(' ', ft_sp_str(ft_strlen(s), list_fl), list_fl);
	ft_init(list_fl);
}
