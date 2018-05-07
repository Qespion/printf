/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 17:12:36 by oespion           #+#    #+#             */
/*   Updated: 2018/05/07 17:43:33 by oespion          ###   ########.fr       */
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
	return (i);
}

void	ft_putnbrn(int nb, int precision)
{
	int	r;
	int	len;

	len = ft_int_len(nb);
	r = 0;
	while (precision > len + r)
	{
		r++;
		ft_putchar('0');
	}
	ft_putnbr(nb);
}
