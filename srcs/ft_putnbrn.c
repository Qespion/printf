/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 17:12:36 by oespion           #+#    #+#             */
/*   Updated: 2018/05/09 18:09:22 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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

void	ft_putnbrn(t_list *printef)
{
	int	r;
	int	len;
	int	len_width;

	len = ft_int_len((int)printef->str);
	r = 0;
	if (len > printef->precision)
		len_width = len;
	else
		len_width = printef->precision;
	while (len_width < printef->width)
	{
		ft_putchar (' ');
		len_width++;
	}
	while (printef->precision > len + r)
	{
		r++;
		ft_putchar('0');
	}
	ft_putnbr((int)printef->str);
}
