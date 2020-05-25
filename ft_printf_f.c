/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 15:03:07 by apuchill          #+#    #+#             */
/*   Updated: 2020/05/25 19:30:34 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			print_spec_f(int *len, t_flags fl, double n)
{
	fl.sign = (n >= 0) ? '+' : '-';
	fl.f = (n >= 0) ? n : -n;
	fl.ulli = (n >= 0) ? n : -n;
	fl = ft_dectoa(fl, fl.precision);
	fl.tmp = ft_ullitoa_base(fl.ulli, DIGITS);
	fl.a = ft_strjoin(fl.tmp, fl.d);
	free(fl.tmp);
	if (fl.hash == 1 && fl.point == 1 && fl.precision == 0)
	{
		fl.tmp = ft_strjoin(fl.a, ".");
		free(fl.a);
		fl.a = fl.tmp;
	}
	print_flags(len, fl);
	free(fl.a);
	free(fl.d);
	if (fl.ulli == 0 && fl.point == 1 && fl.precision == 0)
		ft_putchar_len('0', len);
}
