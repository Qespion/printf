/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 10:18:39 by oespion           #+#    #+#             */
/*   Updated: 2018/05/06 12:06:18 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_printf(const char *format, ...);

int	main()
{
	ft_printf("chaine simple %d & %s & letter = %c \n", 86, "chaine simple x2", 'z');
	printf("chaine simple %s fds %s\n", "vrai printf", "autre string");
	return (0);
}
