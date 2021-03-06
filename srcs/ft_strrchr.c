/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 11:22:36 by oespion           #+#    #+#             */
/*   Updated: 2018/05/03 16:16:39 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strrchr(const char *s, int c)
{
	int r;

	r = ft_strlen(s);
	while (r >= 0)
	{
		if (s[r] == (char)c)
			return ((char*)(s + r));
		r--;
	}
	if ((char)c == 0)
		return ((char*)s);
	return (NULL);
}
