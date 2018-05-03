/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_uppercase.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 15:16:28 by oespion           #+#    #+#             */
/*   Updated: 2018/05/03 16:16:14 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_is_uppercase(char *str)
{
	int r;

	r = 0;
	while (str[r])
		r++;
	if (r == 0)
		return (1);
	r = 0;
	while (str[r] && str[r] <= 'Z' && str[r] >= 'A')
		r++;
	if (str[r] == '\0')
		return (1);
	return (0);
}
