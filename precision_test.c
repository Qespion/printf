/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 13:38:23 by oespion           #+#    #+#             */
/*   Updated: 2018/05/09 19:12:19 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_printf(const char *format, ...);

int main (void)
{
	ft_printf("le mien    = %2.10d\n", 48354);
	printf("le vrai    = % d\n", 42);
	return 0;
}
