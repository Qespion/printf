/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 13:54:53 by oespion           #+#    #+#             */
/*   Updated: 2018/05/11 18:37:15 by oespion          ###   ########.fr       */
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

t_list	*create_struct(void)
{
	t_list	*printef;

	if (!(printef = (t_list*)malloc(sizeof(t_list))))
		return (0);
	printef->nbout = 0;
	printef->precision = -1;
	printef->width = -1;
	printef->increment = 0;
	printef->negative = 0;
	printef->zeros = 0;
	printef->blank = 0;
	printef->positive = 0;
	printef->sharp = 0;
	printef->h = 0;
	printef->hh = 0;
	printef->l = 0;
	printef->ll = 0;
	printef->j = 0;
	printef->z = 0;
	return (printef);
}

t_list	*reset_struct(t_list *printef)
{
	printef->precision = -1;
	printef->width = -1;
	printef->negative = 0;
	printef->zeros = 0;
	printef->blank = 0;
	printef->increment = 0;
	printef->positive = 0;
	printef->sharp = 0;
	printef->h = 0;
	printef->hh = 0;
	printef->l = 0;
	printef->ll = 0;
	printef->j = 0;
	printef->z = 0;
	return (printef);
}
//1000 0000
//0x80