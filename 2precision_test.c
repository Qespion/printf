/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2precision_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 09:57:40 by oespion           #+#    #+#             */
/*   Updated: 2018/05/09 10:03:19 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main (void)
{
	int i = 10;

	for (i = 0; i < 10; i++)
	{
		printf ("|%.*d|\n", i, 10);
	}
	return 0;
}