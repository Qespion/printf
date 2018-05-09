/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 13:54:53 by oespion           #+#    #+#             */
/*   Updated: 2018/05/09 16:18:26 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_convert(int	nb, int base)
{
	if (nb == 0 || base == 10)
		return (nb);
	return (nb % base + (ft_convert((nb / base), base)));
}

const char	*end_of_int(const char *str)
{
	str++;
	while (*str >= '0' && *str <= '9')
		str++;
	return (str);
}