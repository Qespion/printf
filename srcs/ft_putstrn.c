/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 15:57:55 by oespion           #+#    #+#             */
/*   Updated: 2018/05/11 16:48:03 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

void	write_with_precision(char *str, t_list *printef)
{
	int	r;

	r = 0;
	if (printef->precision == -1)
		while (str[r])
		{
			printef->nbout++;
			ft_putchar(str[r++]);
		}
	else
		while (str[r] && r < printef->precision)
		{
			printef->nbout++;
			ft_putchar(str[r++]);
		}
}

void	ft_putstrn(t_list *printef)
{
	int		len_width;
	char	*str;
	char	spaces;

	spaces = ' ';
	if (printef->zeros && printef->negative == 0)
		spaces = '0';
	if (!printef->str)
		return ;
	len_width = printef->precision + 1;
	if (len_width > (int)ft_strlen((char*)printef->str)
			|| printef->precision == -1)
		len_width = ft_strlen((char*)printef->str) + 1;
	if (printef->negative == 0)
		while (len_width++ <= printef->width)
		{
			printef->nbout++;
			ft_putchar(spaces);
		}
	str = (char*)printef->str;
	write_with_precision(str, printef);
	if (printef->negative == 1)
		while (len_width++ <= printef->width)
		{
			printef->nbout++;
			ft_putchar(spaces);
		}
}
