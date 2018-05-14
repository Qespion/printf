/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 11:25:19 by oespion           #+#    #+#             */
/*   Updated: 2018/05/12 16:25:22 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>
#include <stdio.h>

int		int_len(unsigned int nb, int base)
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

char	*ft_convert_base(unsigned int nb, int base)
{
	int 	len;
	char	*total;
	char	*tab;

	tab = "0123456789abcdef";
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
