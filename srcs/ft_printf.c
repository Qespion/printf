/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 11:52:36 by oespion           #+#    #+#             */
/*   Updated: 2018/05/11 19:12:22 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

const char	*ft_flags(const char *format, t_list *printef)
{
	if (*format == '-')
		printef->negative = 1;
	else if (*format == '+')
		printef->positive = 1;
	else if (*format == '0')
		printef->zeros = 1;
	else if (*format == ' ')
		printef->blank = 1;
	else if (*format == '#')
		printef->sharp = 1;
	if (*format == '#' || *format == ' ' || *format == '+' || *format == '-'
			|| *format == '0')
		format++;
	if (*format == '#' || *format == ' ' || *format == '+' || *format == '-'
			|| *format == '0')
		return (ft_flags(format, printef));
	return (format);
}

const char	*ft_width(const char *format, t_list *printef)
{
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

const char	*ft_precision(const char *format, t_list *printef)
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
	ft_get_arg(*format, printef);
	return (format);
}

const char	*ft_lenght_mod(const char *format, t_list *printef)
{
	if (*format == 'h' && format[1] == 'h')
		printef->hh = 1;
	else if (*format == 'l' && format[1] == 'l')
		printef->ll = 1;
	else if (*format == 'h')
		printef->h = 1;
	else if (*format == 'l')
		printef->l = 1;
	else if (*format == 'j')
		printef->j = 1;
	else if (*format == 'z')
		printef->z = 1;
	while (*format == 'h' || *format == 'j' || *format == 'l'
			|| *format == 'z')
		format++;
	return (format);
}

int	ft_printf(const char* format, ...)
{
	t_list	*printef;
	printef = create_struct();
	va_start(printef->ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			format = ft_flags(format, printef);
			format = ft_width(format, printef);
			format = ft_precision(format, printef);
			format = ft_lenght_mod(format, printef);
		}
		printef->increment ? format++ : 0;
		if (*format != '\0')
		{
			printef->nbout++;
			ft_putchar((char)*format);
			format++;
		}
		printef = reset_struct(printef);
	}
	va_end(printef->ap);
//	printf("precision = %d\n", printef->precision);
//	printf("width = %d\n", printef->width);
//			************************************penser a mettre le -1 au retour
//	printf("\nstdout = %d\n", printef->nbout);
	return (printef->nbout);
}
