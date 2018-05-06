/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 10:18:39 by oespion           #+#    #+#             */
/*   Updated: 2018/05/06 13:51:49 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "locale.h"

void	ft_printf(const char *format, ...);

int	main()
{
	ft_printf("chaine simple %d & %s & letter = %c \n", 86, "chaine simple x2", 'z');
	setlocale(LC_ALL, "");
	printf("chaine simple %S ", L"漢字");
	return (0);
}
