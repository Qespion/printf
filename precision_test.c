/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 13:38:23 by oespion           #+#    #+#             */
/*   Updated: 2018/05/11 19:11:07 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_printf(const char *format, ...);

int main (void)
{
	ft_printf("%21%reg");
	printf("\nstdout = %d\n", printf("%21%reg"));
	return (0);
}
