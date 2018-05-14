/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printable_adv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 12:34:52 by oespion           #+#    #+#             */
/*   Updated: 2018/05/14 18:17:15 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

void	printbinary(t_list *p)
{
	char	*bin;
	unsigned int str;

	str = va_arg(p->ap, unsigned int);
	bin = ft_convert_base(str, 2);
	if (p->precision != -1 || p->width != -1)
		ft_putstrn(p, bin);
	else
	{
		p->nbout += ft_strlen(bin);
		ft_putstr(bin);
	}
}

void	printhexa(t_list *p, int maj)
{
	char	*hexa;
	unsigned int nb;

	nb = va_arg(p->ap, unsigned int);
	hexa = ft_convert_base(nb, 16);
	maj ? hexa = ft_toupper(hexa) : 0;
	!*hexa ? hexa = "0" : 0;
	if (*hexa == '0' && p->precision == 0)
		return ;
	if (p->precision != -1 || p->width != -1)
		ft_puthexan(p, hexa, 0);
	else
	{
		p->nbout += 2 +ft_strlen(hexa);
		p->sharp && *hexa != '0'? ft_putstr("0x") : p->nbout-- ;
		p->sharp && *hexa != '0'? 0 : p->nbout-- ;
		ft_putstr(hexa);
	}
}

void	printoctal(t_list *p, int maj)
{
	char	*hexa;
	unsigned int nb;

	nb = va_arg(p->ap, unsigned int);
	hexa = ft_convert_base(nb, 8);
	maj ? hexa = ft_toupper(hexa) : 0;
	!*hexa ? hexa = "0" : 0;
	if (*hexa == '0' && p->precision == 0)
		return ;
	if (p->precision != -1 || p->width != -1)
		ft_puthexan(p, hexa, 1);
	else
	{
		p->sharp ? ft_putstr("0") : p->nbout-- ;
		p->nbout += 1 +ft_strlen(hexa);
		ft_putstr(hexa);
	}
}

void	printunsigned(t_list *p)
{
	unsigned int nbr;

	nbr = va_arg(p->ap, unsigned int);
	if (p->blank == 1 && p->positive == 0)
	{
		ft_putchar(' ');
		p->width--;
		p->nbout++;
	}
	if (p->positive && p->width != -1)
		p->width--;
	if (p->precision != -1 || p->width != -1)
		ft_putnbrnu(p, nbr);
	else
	{
		p->nbout += int_len((int)nbr, 10);
		ft_putnbru(nbr);
	}
}
