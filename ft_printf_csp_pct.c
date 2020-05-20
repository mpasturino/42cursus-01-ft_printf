/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cs_pct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 17:36:54 by apuchill          #+#    #+#             */
/*   Updated: 2020/05/19 14:24:49 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_padding(int *len, t_flags fl)
{
	while (fl.width > fl.precision)
	{
		ft_putchar_len(fl.pad_c, len);
		fl.width--;
	}
}

void		print_spec_pct(int *len, t_flags fl)
{
	if (fl.minus == 1)
		fl.pad_c = ' ';
	fl.precision = 1;
	if (fl.minus == 0)
		print_padding(len, fl);
	ft_putchar_len('%', len);
	if (fl.minus == 1)
		print_padding(len, fl);
}

void		print_spec_c(int *len, t_flags fl, char c)
{
	fl.pad_c = ' ';
	fl.precision = 1;
	if (fl.minus == 0)
		print_padding(len, fl);
	ft_putchar_len(c, len);
	if (fl.minus == 1)
		print_padding(len, fl);
}

void		print_spec_s(int *len, t_flags fl, char *s)
{
	fl.pad_c = ' ';
	if (s == NULL)
		s = "(null)";
	if ((fl.point == 1 && fl.precision > (int)ft_strlen(s)) || fl.point == 0)
		fl.precision = ft_strlen(s);
	if (fl.minus == 0)
		print_padding(len, fl);
	ft_putcstr_len(s, len, fl.precision);
	if (fl.minus == 1)
		print_padding(len, fl);
}

void		print_spec_p(int *len, t_flags fl, unsigned long int p)
{
	fl.pad_c = ' ';
	fl.a = ft_ullitoa_base(p, "0123456789abcdef");
	fl.a = ft_strjoin("0x", fl.a);
	fl.precision = ft_strlen(fl.a);
	if (fl.minus == 0)
		print_padding(len, fl);
	ft_putcstr_len(fl.a, len, 14);
	if (fl.minus == 1)
		print_padding(len, fl);
}