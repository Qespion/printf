/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 13:38:23 by oespion           #+#    #+#             */
/*   Updated: 2018/05/15 18:14:57 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_printf(const char *format, ...);

int main()
{
	ft_printf("@moulitest: %#.o %#.0o", 0, 0);
	printf("%c", '\n');
	printf("\nstdout = %d\n", printf("@moulitest: %#.o %#.0o", 0, 0));
	return (0);
}
