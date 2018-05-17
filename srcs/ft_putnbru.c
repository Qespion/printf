/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbru.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 17:03:11 by oespion           #+#    #+#             */
/*   Updated: 2018/05/17 17:28:54 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbru(long long nb)
{
	if (nb < -9223372036854775807)
	{
		ft_putstr("-9223372036854775808");
		return ;
	}
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar('-');
	}
	if (nb > 9)
	{
		ft_putnbru(nb / 10);
		ft_putnbru(nb % 10);
	}
	else
		ft_putchar('0' + nb);
}