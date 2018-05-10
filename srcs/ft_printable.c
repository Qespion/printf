/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 11:37:15 by oespion           #+#    #+#             */
/*   Updated: 2018/05/10 18:28:45 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

void	prints(t_list *printef)
{
	if (printef->precision != -1 || printef->width != -1)
		ft_putstrn(printef);
	else
		ft_putstr((char*)printef->str);
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
				ft_putchar('+');
		}
		ft_putnbr((int)printef->str);
	}
}

void	printchar(t_list *printef)
{
	if (printef->precision != -1 || printef->width != -1)
		ft_putcharn(printef);
	else
		ft_putchar((char)printef->str);
}

void	printhexa(t_list *printef)
{
	(void)printef->str;
	(void)printef->precision;
}

void	ft_get_arg(char letter, t_list *printef)
{
	if (letter == 's')
		prints(printef);
	if (letter == 'd')
		printnb(printef);
	if (letter == 'c')
		printchar(printef);
	if (letter == 'p')
		printhexa(printef);
}
