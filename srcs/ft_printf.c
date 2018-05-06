/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 16:01:39 by oespion           #+#    #+#             */
/*   Updated: 2018/05/06 14:04:56 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

void	ft_get_arg(char letter, void *str)
{
	if (letter == 's')
		prints((char*)str);
	if (letter == 'd')
		printnb((int)str);
	if (letter == 'c')
		printchar((char)str);
	if (letter == 'p')
		printhexa((int)str);
}

void	ft_printf(const char* format, ...)
{
	int			r;
    va_list 	ap;
	void  		*str;

	r = 0;
	va_start(ap, format);
	while (format[r])
	{
		if (format[r] == '%')
		{
			str = va_arg(ap, void*);
			ft_get_arg(format[++r], str);
			r++;
		}
		ft_putchar((char)format[r++]);
	}
    va_end(ap);
}
