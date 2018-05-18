/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_longlong.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 11:47:44 by oespion           #+#    #+#             */
/*   Updated: 2018/05/18 15:39:50 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

void	ft_putnbr_longlong(long long nb)
{
	if (nb < -9223372036854775807)
		ft_putstr("-9223372036854775808");
	else if (nb > 9)
	{
		ft_putnbr_longlong(nb / 10);
		ft_putnbr_longlong(nb % 10);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr_longlong(nb *= -1);
	}
	else
		ft_putchar('0' + nb);
}
