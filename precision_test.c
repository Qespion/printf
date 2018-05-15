/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 13:38:23 by oespion           #+#    #+#             */
/*   Updated: 2018/05/15 19:24:30 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_printf(const char *format, ...);

int main()
{
	ft_printf("@moulitest: %5.x %#5.0x", 0, 0);
	printf("%c", '\n');
	printf("\nstdout = %d\n", printf("@moulitest: %5.x %5.0x", 0, 0));
	return (0);
}
