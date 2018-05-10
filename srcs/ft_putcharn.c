/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcharn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 18:09:47 by oespion           #+#    #+#             */
/*   Updated: 2018/05/10 17:30:04 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putcharn(t_list *printef)
{
	int		len_width;
	char	*str;
	char	spaces;

	spaces = ' ';
	if (printef->zeros && printef->negative == 0)
		spaces = '0';
		len_width = 1;
	if (printef->negative == 0)
		while (len_width++ < printef->width)
			ft_putchar(spaces);
	str = (char*)printef->str;
	ft_putchar((char)printef->str);
	if (printef->negative == 1)
		while (len_width++ < printef->width)
			ft_putchar(spaces);
}
