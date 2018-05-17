/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexan.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 14:42:06 by oespion           #+#    #+#             */
/*   Updated: 2018/05/17 13:28:28 by oespion          ###   ########.fr       */
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
	p->zeros && !p->negative ? spaces = '0' : 0;
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
	*hexa == '0' && p->sharp ? ft_putchar('0') : 0;
	*hexa == '0' && p->sharp ? p->nbout++ : 0;
	*hexa == '0' && p->sharp ? p->nbout++ : 0;
	*hexa == '0' && !p->sharp && p->width != -1? ft_putchar(' ') : 0;
	while ((int)ft_strlen(hexa) < tmp)
	{
		p->nbout++;
		ft_putchar('0');
		tmp--;
	}
}

void	ft_puthexan(t_list *p, char *hexa, int oct, int maj)
{
	if (p->negative)
	{
		if (p->sharp && *hexa != '0')
		{
			if (maj)
				oct ? ft_putchar('0') : ft_putstr("0X");
			else
				oct ? ft_putchar('0') : ft_putstr("0x");
			p->nbout += 2;
		}
		ft_gprecision(hexa, p);
		*hexa == '0' ? 0 : ft_putstr(hexa);
		ft_gwidth(hexa, p, oct);
		p->nbout += ft_strlen(hexa);
	}
	else
	{
		!p->zeros ? ft_gwidth(hexa, p, oct) : 0;
		if (p->sharp && *hexa != '0')
		{
			if (maj)
				oct ? ft_putchar('0') : ft_putstr("0X");
			else
				oct ? ft_putchar('0') : ft_putstr("0x");
			p->nbout += 2;
		}
		p->zeros ? ft_gwidth(hexa, p, oct) : 0;
		ft_gprecision(hexa, p);
		*hexa == '0' ? 0 : ft_putstr(hexa);
		p->nbout += ft_strlen(hexa);
	}
}
