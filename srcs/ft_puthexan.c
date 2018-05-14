/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexan.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 14:42:06 by oespion           #+#    #+#             */
/*   Updated: 2018/05/14 18:15:33 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

void	ft_gwidth(char *hexa, t_list *p, int oct)
{
	int	max;
	int	width_tmp;
	char	spaces;

	spaces = ' ';
	width_tmp = p->width;
	p->zeros ? spaces = '0' : 0;
	if ((int)ft_strlen(hexa) > p->precision)
		max = (int)ft_strlen(hexa);
	else
		max = p->precision;
	if (p->sharp && *hexa != '0')
	{
		max++;
		oct ? 0 : max++;
	}
	while (max < width_tmp)
	{
		width_tmp--;
		p->nbout++;
		ft_putchar(spaces);
	}
}

void	ft_gprecision(char *hexa, t_list *p)
{
	int	tmp;

	tmp = p->precision;
	while ((int)ft_strlen(hexa) < tmp)
	{
		p->nbout++;
		ft_putchar('0');
		tmp--;
	}
}

void	ft_puthexan(t_list *p, char *hexa, int oct)
{
	if (p->negative)
	{
		if (p->sharp && *hexa != '0')
		{
			oct ? ft_putchar('0') : ft_putstr("0x");
			p->nbout += 2;
		}
		ft_gprecision(hexa, p);
		ft_putstr(hexa);
		ft_gwidth(hexa, p, oct);
		p->nbout += ft_strlen(hexa);
	}
	else
	{
		ft_gwidth(hexa, p, oct);
		if (p->sharp && *hexa != '0')
		{
			oct ? ft_putchar('0') : ft_putstr("0x");
			p->nbout += 2;
		}
		ft_gprecision(hexa, p);
		ft_putstr(hexa);
		p->nbout += ft_strlen(hexa);
	}
}