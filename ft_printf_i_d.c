/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_i_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 13:25:14 by apuchill          #+#    #+#             */
/*   Updated: 2020/05/17 18:55:06 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa(int n)
{
	char	*str;
	long	nbr;
	size_t	size;

	nbr = n;
	size = (n >= 0) ? 1 : 2;
	nbr = n > 0 ? n : -n;
	while (n /= 10)
		size++;
	if (!(str = (char *)malloc(size + 1)))
		return (0);
	str[size--] = '\0';
	while (nbr > 0)
	{
		str[size--] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (size == 0 && str[1] == '\0')
		str[0] = '0';
	else if (size == 0 && str[1] != '\0')
		str[0] = '-';
	return (str);
}

static void	print_padding(int *len, t_flags fl)
{
	while (fl.width > fl.precision)
	{
		ft_putchar_len(' ', len);
		fl.width--;
	}
}

void	print_spec_i_d(int *len, t_flags fl, int n)
{
	char	*a;

	//printf("[n = %i]", n);
	a = ft_itoa(n);
	//printf("[a = \"%s\"]", a);
	fl.precision = ft_strlen(a);
	if (fl.minus == 0)
		print_padding(len, fl);
	if (fl.plus == 1 && n > 0)
		ft_putchar_len('+', len);
	ft_putcstr_len(a, len, ft_strlen(a));
	if (fl.minus == 1)
		print_padding(len, fl);
}