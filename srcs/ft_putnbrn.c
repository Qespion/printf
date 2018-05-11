/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 17:12:36 by oespion           #+#    #+#             */
/*   Updated: 2018/05/11 19:08:12 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	ft_int_len(int nb)
{
	int	i;

	i = 1;
	while (nb > 1)
	{
		nb /= 10;
		i++;
	}
	return (i - 1);
}

void	ft_pos(t_list *printef, int neg)
{
	if (printef->positive && !neg)
	{
		printef->nbout++;
		ft_putchar('+');
	}
	if (neg)
	{
		printef->nbout++;
		ft_putchar('-');
	}
	neg = 0;
	printef->positive = 0;
}

void	ft_get_width(t_list *printef, int nbr)
{
	int	spaces;
	int	max;
	int	width_tmp;

	width_tmp = printef->width;
	spaces = ' ';
	if (ft_int_len(nbr) > printef->precision)
		max = ft_int_len(nbr);
	else
		max = printef->precision;
	while (max < width_tmp)
	{
		width_tmp--;
		printef->nbout++;
		ft_putchar(spaces);
	}
}

void	ft_get_precision(int nbr, t_list *printef)
{
	int	precision_tmp;

	precision_tmp = printef->precision;
	while (ft_int_len(nbr) < precision_tmp)
	{
		ft_putchar('0');
		precision_tmp--;
	}
}

void	ft_putnbrn(t_list *printef)
{
	int		nbr;
	int		neg;

	nbr = (int)printef->str;
	neg = 0;
	if (nbr < 0)
	{
		printef->width--;
		neg = 1;
	}
	nbr = ft_abs(nbr);
	if (printef->negative)
	{
		ft_pos(printef, neg);
		ft_get_precision(nbr, printef);
		ft_putnbr(nbr);
		ft_get_width(printef, nbr);
		printef->nbout += int_len(nbr, 10);
	}
	else
	{
		printef->nbout += int_len(nbr, 10);
		ft_get_width(printef, nbr);
		ft_pos(printef, neg);
		ft_get_precision(nbr, printef);
		ft_putnbr(nbr);
	}
}
