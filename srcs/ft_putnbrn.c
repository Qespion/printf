/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 17:12:36 by oespion           #+#    #+#             */
/*   Updated: 2018/05/18 17:45:55 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

void	ft_pos(t_list *p)
{
	if (p->positive == 1 && !p->neg)
	{
		p->nbout++;
		ft_putchar('+');
	}
	if (p->neg == 1)
	{
		p->nbout++;
		ft_putchar('-');
	}
	p->neg = 2;
	p->positive = 2;
}

void	ft_get_width(t_list *p, unsigned int nbr)
{
	int	spaces;
	int	max;
	int	width_tmp;

	max = 0;
	width_tmp = p->width;
	spaces = ' ';
	p->neg != 0 && !p->positive ? max++ : 0;
	p->width != -1 && nbr == 0  && p->precision == 0? max-- : 0;
	p->zeros && p->precision == -1 && !p->negative ? spaces = '0' : 0;
	if (spaces == '0' && p->neg && !p->negative)
		ft_pos(p);
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

	precision_tmp = p->precision;
	p->neg ? ft_pos(p): 0;
	p->positive ? ft_pos(p) : 0;
	p->precision == 0 && nbr == 0 ? precision_tmp = 0 : 0;
	while (ft_int_len(nbr) < precision_tmp)
	{
		ft_putchar('0');
		p->nbout++;
		precision_tmp--;
	}
}

void	ft_putnbrn(t_list *p, long long nbr)
{
	if (nbr < 0)
		p->neg = 1;
	nbr = ft_abs(nbr);
	nbr == 0 && p->precision == -1 ? p->nbout++ : 0;
	if (p->negative)
	{
		p->neg ? p->width-- : 0;
		ft_get_precision(nbr, p);
		ft_putnbr_longlong(nbr);
		ft_get_width(p, nbr);
		p->nbout += int_len(nbr, 10);
	}
	else
	{
	//	printf("\nNBOUT->%d\n", p->nbout);
		p->nbout += ft_int_len(nbr);
		ft_get_width(p, nbr);
		ft_get_precision(nbr, p);
		ft_putnbr_longlong(nbr);
	}
}

void	ft_putnbrnu(t_list *p, unsigned long long nbr)
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
