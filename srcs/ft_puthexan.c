/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexan.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 14:42:06 by oespion           #+#    #+#             */
/*   Updated: 2018/05/11 15:47:13 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_gwidth(char *hexa, t_list *printef)
{
	int	max;
	int	width_tmp;

	width_tmp = printef->width;
	if ((int)ft_strlen(hexa) > printef->precision)
		max = (int)ft_strlen(hexa);
	else
		max = printef->precision;
	while (max < width_tmp)
	{
		width_tmp--;
		printef->nbout++;
		ft_putchar(' ');
	}
}

void	ft_gprecision(char *hexa, t_list *printef)
{
	int	tmp;

	tmp = printef->precision;
	while ((int)ft_strlen(hexa) < tmp)
	{
		printef->nbout++;
		ft_putchar('0');
		tmp--;
	}
}

void	ft_puthexan(t_list *printef, char *hexa)
{
	if (printef->negative)
	{
		ft_gprecision(hexa, printef);
		ft_putstr(hexa);
		ft_gwidth(hexa, printef);
		printef->nbout += ft_strlen(hexa);
	}
	else
	{
		ft_gwidth(hexa, printef);
		ft_gprecision(hexa, printef);
		ft_putstr(hexa);
		printef->nbout += ft_strlen(hexa);
	}
}