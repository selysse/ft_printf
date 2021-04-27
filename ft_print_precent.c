/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_precent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselyse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 23:57:35 by gselyse           #+#    #+#             */
/*   Updated: 2020/07/27 20:39:28 by gselyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_precent(t_lst *list_fl)
{
	if (list_fl->flag == -1 && list_fl->width > 1)
		ft_putchar(' ', ft_sp_str(1, list_fl), list_fl);
	if (list_fl->flag == 0 && list_fl->width > 1)
		ft_putchar('0', list_fl->width - 1, list_fl);
	ft_putchar('%', 1, list_fl);
	if (list_fl->flag == 1 && list_fl->width > 1)
		ft_putchar(' ', ft_sp_str(1, list_fl), list_fl);
	ft_init(list_fl);
}
