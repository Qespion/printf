/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 11:37:15 by oespion           #+#    #+#             */
/*   Updated: 2018/05/11 19:10:21 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

void	prints(t_list *printef)
{
	if (printef->precision != -1 || printef->width != -1)
		ft_putstrn(printef);
	else
	{
		printef->nbout += ft_strlen((char*)printef->str);
		ft_putstr((char*)printef->str);
	}
}

void	printnb(t_list *printef)
{
	if (printef->blank == 1 && printef->positive == 0)
	{
		ft_putchar(' ');
		printef->width--;
	}
	if (printef->positive && printef->width != -1)
		printef->width--;
	if (printef->precision != -1 || printef->width != -1)
		ft_putnbrn(printef);
	else
	{
		if (printef->positive)
		{
			if ((int)printef->str >= 0)
			{
				printef->nbout++;
				ft_putchar('+');
			}
		}
		printef->nbout += int_len((int)printef->str, 10);
		ft_putnbr((int)printef->str);
	}
}

void	printchar(t_list *printef, char letter)
{
	if ((printef->precision != -1 || printef->width != -1)
			&& letter == '%')
		ft_putcharnf(printef);
	else if (printef->precision != -1 || printef->width != -1)
		ft_putcharn(printef);
	else
	{
		if (letter != '%')
		{
			printef->nbout++;
			ft_putchar((char)printef->str);
		}
	}
}

void	printhexa(t_list *printef)
{
	char	*hexa;

	hexa = ft_convert_base((int)printef->str, 16);
	if (printef->precision != -1 || printef->width != -1)
		ft_puthexan(printef, hexa);
	else
		ft_putstr(hexa);
}

void	ft_get_arg(char letter, t_list *printef)
{
	if (letter == 's' || letter == 'd' || letter == 'c' || letter == 'x'
			|| letter == 'b' || letter == 'i')
	{
		printef->increment = 1;
		printef->str = va_arg(printef->ap, void*);
	}
	if (letter == 's')
		prints(printef);
	else if (letter == 'd' || letter == 'i')
		printnb(printef);
	else if (letter == 'c' || letter == '%')
		printchar(printef, letter);
	else if (letter == 'x')
		printhexa(printef);
	else if (letter == 'b')
		printbinary(printef);
}
