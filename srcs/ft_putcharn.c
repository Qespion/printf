/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcharn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 18:09:47 by oespion           #+#    #+#             */
/*   Updated: 2018/05/09 18:14:45 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putcharn(t_list *printef)
{
	int	r;

	r = 1;
	if (!printef->str)
		return ;
	if (printef->width != -1)
		while (printef->width > r)
		{
			ft_putchar(' ');
			r++;
		}
	ft_putchar((char)printef->str);
}