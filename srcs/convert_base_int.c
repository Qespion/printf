/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_base_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 14:28:41 by oespion           #+#    #+#             */
/*   Updated: 2018/05/16 14:38:19 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

int		int_len_int(int nb, int base)
{
	int	len;

	len = 0;
	while (nb > 0)
	{
		nb /= base;
		len++;
	}
	return (len);
}

char	*ft_convert_base_int(int nb, int base)
{
	int 	len;
	char	*total;
	char	*tab;

	tab = "0123456789abcdef";
	if (nb < 0)
		nb = ft_abs(nb);
	len = int_len(nb, base);
	if(!(total = (char*)malloc(sizeof(char) * len)))
		return (0);
	total[len--] = '\0';
	while (len >= 0)
	{
		total[len] = tab[nb % base];
		nb /= base;
		len--;
	}
	return (total);
}
