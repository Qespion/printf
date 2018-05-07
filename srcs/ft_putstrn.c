/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 15:57:55 by oespion           #+#    #+#             */
/*   Updated: 2018/05/07 17:25:27 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putstrn(char *str, int n)
{
	int	r;

	r = 0;
	if (!str)
		return ;
	while (str[r] && r < n)
	{
		ft_putchar(str[r]);
		r++;
	}
}
