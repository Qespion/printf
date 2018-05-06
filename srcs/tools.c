/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 13:54:53 by oespion           #+#    #+#             */
/*   Updated: 2018/05/06 14:03:17 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_convert(int	nb, int base)
{
	if (nb == 0 || base == 10)
		return (nb);
	return (nb % base + (ft_convert((nb / base), base)));
}
