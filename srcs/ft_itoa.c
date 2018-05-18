/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 11:19:36 by oespion           #+#    #+#             */
/*   Updated: 2018/05/18 13:58:31 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_size(long long n)
{
	int size;

	size = 0;
	if (n == 0)
		return (1);
	if (n < -9223372036854775807)
		return (21);
	if (n < 0)
	{
		size++;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char		*ft_itoa(long long n)
{
	int		size;
	char	*str;

	size = ft_size(n) - 1;
	if (n < -9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
	if (!(str = (char*)malloc(sizeof(char) * (size + 2))))
		return (0);
	str[size + 1] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n > 9)
	{
		str[size--] = n % 10 + '0';
		n /= 10;
	}
	str[size] = n + '0';
	return (str);
}
