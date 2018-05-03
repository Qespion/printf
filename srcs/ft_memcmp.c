/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 11:20:35 by oespion           #+#    #+#             */
/*   Updated: 2018/05/03 16:16:20 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			r;
	unsigned char	*temp_s1;
	unsigned char	*temp_s2;

	temp_s1 = (unsigned char*)s1;
	temp_s2 = (unsigned char*)s2;
	r = 0;
	while (r < n)
	{
		if (temp_s1[r] != temp_s2[r])
			return (temp_s1[r] - temp_s2[r]);
		r++;
	}
	return (0);
}
