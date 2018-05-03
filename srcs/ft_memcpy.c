/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 11:34:02 by oespion           #+#    #+#             */
/*   Updated: 2018/05/03 16:16:20 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	r;

	r = 0;
	while (r < n)
	{
		((char*)dst)[r] = ((char*)src)[r];
		r++;
	}
	return ((void*)dst);
}
