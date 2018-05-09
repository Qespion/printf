/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 16:01:39 by oespion           #+#    #+#             */
/*   Updated: 2018/05/09 11:52:31 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int		ft_precision(const char *format, void *next)
{
	int		nb;

	nb = 0;
	printf("%s\n", next);
	if (*format == '*')
		return ((int)next);
	nb = ft_atoi(format);
	return (nb);
}

void	ft_get_arg(char letter, void *str, int precision)
{
	if (letter == 's')
		prints((char*)str, precision);
	if (letter == 'd')
		printnb((int)str, precision);
	if (letter == 'c')
		printchar((char)str, precision);
	if (letter == 'p')
		printhexa((int)str, precision);
}

void	ft_printf(const char* format, ...)
{
    va_list 	ap;
	void  		*str;
	int			precision;
	void		*next;

	precision = -1;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '.')
			{
				if (format[1] == '*')
				{
					next = va_arg(ap, void*);
				}
				precision = ft_precision(&format[1], next);
				format = end_of_int(format);
			}
			str = va_arg(ap, void*);
			ft_get_arg(*format, str, precision);
			format++;
		}
		ft_putchar((char)*format);
		format++;
	}
    va_end(ap);
}
