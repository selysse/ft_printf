/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselyse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 23:30:32 by gselyse           #+#    #+#             */
/*   Updated: 2020/07/27 20:05:36 by gselyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_init(t_lst *list_fl)
{
	list_fl->flag = -1;
	list_fl->width = 0;
	list_fl->precision = -1;
	list_fl->zero = 0;
	list_fl->type = '\0';
}

static void		ft_parses(t_lst *list_fl, const char **str, va_list argv)
{
	ft_init(list_fl);
	ft_parflags(list_fl, str);
	ft_parwidth(list_fl, str, argv);
	ft_parprec(list_fl, str, argv);
}

static int		ft_print_value(char str, va_list argv, t_lst *list_fl)
{
	int	res;

	res = 0;
	if (str == (list_fl->type = 'c'))
		ft_print_char(list_fl, argv);
	else if (str == (list_fl->type = 's'))
		ft_print_str(list_fl, argv);
	else if (str == (list_fl->type = 'p'))
		res = ft_print_ptr(list_fl, argv);
	else if (str == (list_fl->type = 'd'))
		res = ft_print_int(list_fl, argv);
	else if (str == (list_fl->type = 'i'))
		res = ft_print_int(list_fl, argv);
	else if (str == (list_fl->type = 'u'))
		res = ft_print_unsigned(list_fl, argv);
	else if (str == (list_fl->type = 'x'))
		res = ft_print_hex(list_fl, argv);
	else if (str == (list_fl->type = 'X'))
		res = ft_print_hex(list_fl, argv);
	else if (str == (list_fl->type = '%'))
		ft_print_precent(list_fl);
	if (res)
		return (res);
	return (0);
}

int				ft_printf(const char *str, ...)
{
	va_list	argv;
	t_lst	list_fl;
	int		res;

	if (!str)
		return (-1);
	va_start(argv, str);
	list_fl.length = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			ft_parses(&list_fl, &str, argv);
			if ((res = ft_print_value(*(str + 1), argv, &list_fl)))
				return (res);
			str++;
		}
		else
			ft_putchar(*str, 1, &list_fl);
		if (*str != '\0')
			str++;
	}
	va_end(argv);
	return (list_fl.length);
}
