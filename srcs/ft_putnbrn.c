/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 17:12:36 by oespion           #+#    #+#             */
/*   Updated: 2018/05/14 19:53:22 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

void	ft_pos(t_list *p)
{
	if (p->positive && !p->neg)
	{
		p->nbout++;
		ft_putchar('+');
	}
	if (p->neg)
	{
		p->nbout++;
		ft_putchar('-');
	}
	p->neg = 0;
	p->positive = 0;
}

void	ft_get_width(t_list *p, unsigned int nbr)
{
	int	spaces;
	int	max;
	int	width_tmp;

	max = 0;
	width_tmp = p->width;
	spaces = ' ';
	p->neg ? max = 1 : 0;
	p->zeros && p->precision == -1 ? spaces = '0' : 0;
	if (spaces == '0' && p->neg && !p->negative)
	{
		if (p->positive)
		{
			p->nbout++;
			ft_putchar('+');
		}
		else
			ft_pos(p);
	}
	spaces == '0' && !p->negative && p->positive ? ft_pos(p): 0;
	if (ft_int_len(nbr) > p->precision)
		max += ft_int_len(nbr);
	else
		max += p->precision;
	while (max < width_tmp--)
	{
		p->nbout++;
		ft_putchar(spaces);
	}
}

void	ft_get_precision(unsigned int nbr, t_list *p)
{
	int	precision_tmp;

	if (p->precision < p->width)
		precision_tmp = p->precision - ft_int_len(nbr);
	else
		precision_tmp = p->precision;
	p->neg ? ft_pos(p): 0;
	p->positive ? ft_pos(p) : 0;
	while (ft_int_len(nbr) < precision_tmp)
	{
		ft_putchar('0');
		p->nbout++;
		precision_tmp--;
	}
}

void	ft_putnbrn(t_list *p, int nbr)
{
	if (nbr < 0)
		p->neg = 1;
	nbr = ft_abs(nbr);
	if (p->negative)
	{
		ft_get_precision(nbr, p);
		ft_putnbr(nbr);
		ft_get_width(p, nbr);
		p->nbout += int_len(nbr, 10);
	}
	else
	{
		p->nbout += int_len(nbr, 10);
		ft_get_width(p, nbr);
		ft_get_precision(nbr, p);
		ft_putnbr(nbr);
	}
}

void	ft_putnbrnu(t_list *p, unsigned int nbr)
{
	if (p->negative)
	{
		ft_get_precision(nbr, p);
		ft_putnbru(nbr);
		ft_get_width(p, nbr);
		p->nbout += int_len(nbr, 10);
	}
	else
	{
		p->nbout += int_len(nbr, 10);
		ft_get_width(p, nbr);
		ft_get_precision(nbr, p);
		ft_putnbru(nbr);
	}
}
