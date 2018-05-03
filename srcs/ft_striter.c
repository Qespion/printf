/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 11:22:18 by oespion           #+#    #+#             */
/*   Updated: 2018/05/03 16:16:33 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_striter(char *s, void (*f)(char *))
{
	char	*cpy_s;

	cpy_s = s;
	if (!s || !f)
		return ;
	while (*cpy_s)
	{
		(*f)(cpy_s);
		cpy_s++;
	}
}
