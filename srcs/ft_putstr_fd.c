/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 11:48:42 by oespion           #+#    #+#             */
/*   Updated: 2018/05/03 16:16:27 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putstr_fd(char const *s, int fd)
{
	int	r;

	r = 0;
	if (!s)
		return ;
	while (s[r])
	{
		write(fd, &s[r], 1);
		r++;
	}
}
