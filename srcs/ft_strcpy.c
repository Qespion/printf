/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 11:22:03 by oespion           #+#    #+#             */
/*   Updated: 2018/05/03 16:16:30 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strcpy(char *dest, const char *src)
{
	int	r;

	r = 0;
	while (src[r])
	{
		dest[r] = src[r];
		r++;
	}
	dest[r] = '\0';
	return (dest);
}
