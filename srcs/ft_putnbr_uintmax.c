/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_uintmax.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 11:43:45 by oespion           #+#    #+#             */
/*   Updated: 2018/05/18 13:20:42 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr_uintmax(uintmax_t nb)
{
	if (nb > 9)
	{
		ft_putnbr_uintmax(nb / 10);
		ft_putnbr_uintmax(nb % 10);
	}
	else
		ft_putchar('0' + nb);
}
