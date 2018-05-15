/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 11:37:15 by oespion           #+#    #+#             */
/*   Updated: 2018/05/15 14:41:15 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

void	prints(t_list *p)
{
	char*	str;

	str = va_arg(p->ap, char*);
	if (p->precision != -1 || p->width != -1)
		ft_putstrn(p, str);
	else
	{
		p->nbout += ft_strlen(str);
		ft_putstr(str);
	}
}

void	printnb(t_list *p)
{
	int	nbr;

	nbr = va_arg(p->ap, int);
	if (p->blank == 1 && p->positive == 0 && nbr > 0)
	{
		ft_putchar(' ');
		p->width--;
		p->nbout++;
	}
	p->positive && p->width != -1 ? p->width-- : 0;
	if (!p->precision && nbr == 0)
	{
		ft_get_width(p, 0);
		return ;
	}
	if (p->precision != -1 || p->width != -1)
		ft_putnbrn(p, nbr);
	else
	{
		if (p->positive && nbr >= 0)
		{
			p->nbout++;
			ft_putchar('+');
		}
		nbr <= 0 ? p->nbout++ : 0;
		p->nbout += int_len(ft_abs(nbr), 10);
		ft_putnbr(nbr);
	}
}

void	printchar(t_list *p, char letter)
{
	char c;
	if (letter != '%')
		c = va_arg(p->ap, int);
	if ((p->precision != -1 || p->width != -1)
			&& letter == '%')
		ft_putcharnf(p);
	else if (p->precision != -1 || p->width != -1)
	{
		ft_putcharn(p, c);
	}
	else
	{
		if (letter == '%')
			ft_putchar('%');
		if (letter != '%')
		{
			p->nbout++;
			ft_putchar(c);
		}
	}
}

void	ft_get_arg(char letter, t_list *p)
{
	if (letter == 's' || letter == 'd' || letter == 'c' || letter == 'x'
			|| letter == 'b' || letter == 'i' || letter == 'X' || letter == 'u'
			|| letter == 'o' || letter == 'O')
		p->increment = 1;
	if (letter == 's')
		prints(p);
	else if (letter == 'd' || letter == 'i')
		printnb(p);
	else if (letter == 'c' || letter == '%')
		printchar(p, letter);
	else if (letter == 'x')
		printhexa(p, 0);
	else if (letter == 'b')
		printbinary(p);
	else if (letter == 'X')
		printhexa(p, 1);
	else if (letter == 'u')
		printunsigned(p);
	else if (letter == 'o')
		printoctal(p, 0);
	else if (letter == 'O')
		printoctal(p, 1);
}
