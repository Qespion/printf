/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 11:52:36 by oespion           #+#    #+#             */
/*   Updated: 2018/05/09 17:25:43 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

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

const char	*ft_width(const char *format, t_list *printef)
{
	format++;
	while ((*format >= '0' && *format <= '9') || *format == '*')
	{
		if (*format >= '0' && *format <= '9')
		{
			printef->width = ft_atoi(format);
			format = end_of_int(format);
		}
		if (*format == '*')
		{
			printef->width = (int)va_arg(printef->ap, int);
			format++;
		}
	}
	return (format);
}

const char	*ft_precision(const char* format, t_list *printef)
{
	if (*format == '.')
	{
		format++;
		while ((*format >= '0' && *format <= '9') || *format == '*')
		{
			if (*format >= '0' && *format <= '9')
			{
				printef->precision = ft_atoi(format);
				format = end_of_int(format);
			}
			if (*format == '*')
			{
				printef->precision = (int)va_arg(printef->ap, int);
				format++;
			}
		}
	}
	printef->str = va_arg(printef->ap, void*);
	ft_get_arg(*format, printef);
	format++;
	return (format);
}

void	ft_printf(const char* format, ...)
{
	t_list	*printef;

	if (!(printef = (t_list*)malloc(sizeof(t_list))))
		return ;
	printef->precision = -1;
	printef->width = -1;
	va_start(printef->ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format = ft_width(format, printef);
			format = ft_precision(format, printef);
		}
		ft_putchar((char)*format);
		format++;
	}
	va_end(printef->ap);
	printf("precision = %d\n", printef->precision);
	printf("width = %d\n", printef->width);
}
