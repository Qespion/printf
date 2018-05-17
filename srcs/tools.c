/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 13:54:53 by oespion           #+#    #+#             */
/*   Updated: 2018/05/17 15:30:53 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

const char	*end_of_int(const char *str)
{
	str++;
	while (*str >= '0' && *str <= '9')
		str++;
	return (str);
}

int	ft_int_len(uintmax_t nb)
{
	int	i;

	i = 1;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i - 1);
}

t_list	*create_struct(void)
{
	t_list	*p;

	if (!(p = (t_list*)malloc(sizeof(t_list))))
		return (0);
	p->nbout = 0;
	p->precision = -1;
	p->width = -1;
	p->increment = 0;
	p->negative = 0;
	p->zeros = 0;
	p->blank = 0;
	p->positive = 0;
	p->sharp = 0;
	p->h = 0;
	p->neg = 0;
	p->hh = 0;
	p->l = 0;
	p->ll = 0;
	p->j = 0;
	p->z = 0;
	return (p);
}

t_list	*reset_struct(t_list *p)
{
	p->precision = -1;
	p->width = -1;
	p->negative = 0;
	p->zeros = 0;
	p->blank = 0;
	p->neg = 0;
	p->increment = 0;
	p->positive = 0;
	p->sharp = 0;
	p->h = 0;
	p->hh = 0;
	p->l = 0;
	p->ll = 0;
	p->j = 0;
	p->z = 0;
	return (p);
}
//1000 0000
//0x80