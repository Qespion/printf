/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longlong_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 15:30:13 by oespion           #+#    #+#             */
/*   Updated: 2018/05/17 17:20:12 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	longlong_len(long long nb)
{
	int	i;

	i = 0;
	if (nb < -9223372036854775807)
		return (19);
	if (nb < 0)
		nb *= -1;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}