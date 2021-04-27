/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselyse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 01:59:42 by gselyse           #+#    #+#             */
/*   Updated: 2020/07/27 20:42:35 by gselyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct		s_lst
{
	int		flag;
	int		width;
	int		precision;
	int		length;
	int		zero;
	char	type;
}					t_lst;

int					ft_printf(const char *str, ...);
int					ft_atoi(const char *nptr);
char				*ft_itoa(long long int num, int base);
void				ft_flags_zero(char **s, t_lst *list_fl);
void				ft_flags_minus(char *s, t_lst *list_fl);
void				ft_print_minus(char **s, t_lst *list_fl);
int					ft_sp_num(int len, t_lst *list_fl);
int					ft_sp_str(int len, t_lst *list_fl);
void				ft_print_char(t_lst *list_fl, va_list argv);
void				ft_print_str(t_lst *list_fl, va_list argv);
int					ft_print_ptr(t_lst *list_fl, va_list argv);
int					ft_print_int(t_lst *list_fl, va_list argv);
int					ft_print_unsigned(t_lst *list_fl, va_list argv);
int					ft_print_hex(t_lst *list_fl, va_list argv);
void				ft_print_precent(t_lst *list_fl);
void				ft_init(t_lst *list_fl);
void				ft_parwidth(t_lst *list_fl, const char **str, va_list argv);
void				ft_parprec(t_lst *list_fl, const char **str, va_list argv);
void				ft_parflags(t_lst *list_fl, const char **str);
void				ft_putchar(char c, int n, t_lst *list_fl);
void				ft_toupper(char *c);
void				ft_putstr(char *s, t_lst *list_fl);
int					ft_isdigit(int c);
int					ft_strlen(const char *s);
char				*ft_strdup(const char *s);

#endif
