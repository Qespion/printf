/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 11:52:36 by oespion           #+#    #+#             */
/*   Updated: 2018/05/03 16:16:31 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strdup(const char *src)
{
	int		r;
	char	*dest;

	r = 0;
	while (src[r])
		r++;
	if (!(dest = (char*)malloc(sizeof(char) * (r + 1))))
		return (0);
	r = 0;
	while (src[r])
	{
		dest[r] = src[r];
		r++;
	}
	dest[r] = '\0';
	return (dest);
}
