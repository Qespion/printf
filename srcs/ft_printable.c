/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 11:37:15 by oespion           #+#    #+#             */
/*   Updated: 2018/05/07 17:34:13 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	prints(char	*str, int precision)
{
	if (precision != -1)
		ft_putstrn(str, precision);
	else
		ft_putstr(str);
}

void	printnb(int str, int precision)
{
	if (precision != -1)
		ft_putnbrn(str, precision);
	else
		ft_putnbr(str);
}

void	printchar(char str, int precision)
{
	(void)precision;
	ft_putchar(str);
}

void	printhexa(int str, int precision)
{
	(void)str;
	(void)precision;
}
