/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 15:03:08 by apuchill          #+#    #+#             */
/*   Updated: 2020/05/20 15:03:51 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_width(int *len, t_flags fl)
{
	if (fl.sign == '-' || (fl.plus == 1 && fl.sign == '+') ||
		(fl.space == 1 && fl.plus == 0 && fl.sign == '+'))
		fl.width--;
	fl.precision = (fl.precision > fl.size) ? fl.precision : fl.size;
	if (fl.pad_c == '0' && (fl.minus == 1 || fl.point == 1))
		fl.pad_c = ' ';
	while (fl.width > fl.precision)
	{
		ft_putchar_len(fl.pad_c, len);
		fl.width--;
	}
}

void	print_zeros(int *len, t_flags fl)
{
	if (fl.spe_c == 'x' && fl.hash == 1 && fl.ulli != 0)
		ft_putcstr_len("0x", len, 2);
	if (fl.spe_c == 'X' && fl.hash == 1 && fl.ulli != 0)
		ft_putcstr_len("0X", len, 2);
	if (fl.spe_c == 'o' && fl.hash == 1 && (fl.ulli != 0 ||
		(fl.point == 1 && fl.precision == 0)))
		ft_putchar_len('0', len);
	if (fl.minus == 0 && fl.pad_c == '0')
		print_width(len, fl);
	if (fl.point == 1)
	{
		fl.j = fl.precision;
		while (fl.j-- > fl.size)
			ft_putchar_len('0', len);
	}
}

void	print_flags(int *len, t_flags fl)
{
	fl.size = ft_strlen(fl.a);
	if (fl.ulli == 0 && fl.point == 1 && fl.precision == 0)
		fl.width++;
	if ((fl.spe_c == 'x' || fl.spe_c == 'X') && fl.hash == 1 && fl.ulli != 0)
		fl.width -= 2;
	if (fl.spe_c == 'o' && fl.hash == 1 && (fl.ulli != 0 ||
		(fl.point == 1 && fl.precision == 0)))
		fl.width -= 1;
	if (fl.spe_c == 'o' && fl.hash == 1 && fl.ulli != 0 && fl.point == 1)
		fl.precision -= 1;
	if (fl.point == 1)
		fl.pad_c = ' ';
	if (fl.minus == 0 && fl.pad_c == ' ')
		print_width(len, fl);
	if (fl.sign == '-' || (fl.plus == 1 && fl.sign == '+'))
		ft_putchar_len(fl.sign, len);
	if (fl.space == 1 && fl.plus == 0 && fl.sign == '+')
		ft_putchar_len(' ', len);
	print_zeros(len, fl);
	if (!(fl.ulli == 0 && fl.point == 1 && fl.precision == 0))
		ft_putcstr_len(fl.a, len, ft_strlen(fl.a));
	if (fl.minus == 1)
		print_width(len, fl);
}
