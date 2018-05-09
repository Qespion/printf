/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 11:37:15 by oespion           #+#    #+#             */
/*   Updated: 2018/05/09 15:16:28 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	prints(t_list *printef)
{
	if (printef->precision != -1 || printef->width != -1)
		ft_putstrn(printef->str, printef->precision);
	else
		ft_putstr((char*)printef->str);
}

void	printnb(t_list *printef)
{
	if (printef->precision != -1 || printef->width != -1)
		ft_putnbrn(printef);
	else
		ft_putnbr((int)printef->str);
}

void	printchar(t_list *printef)
{
	ft_putchar((char)printef->str);
}

void	printhexa(t_list *printef)
{
	(void)printef->str;
	(void)printef->precision;
}
