

/* ************************************************************************** */
/*                                                                            */
/*                  Aligné sur la STACK                                      :::      ::::::::   */
/*   BEST_AFF_Z.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 by ebouvier en piscine		   #+#    #+#             */
/*   Updated: 2018/05/12 by ebouvier en piscine       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
int	main(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	j = 0;
	if (argc != 2)
	{
		write(1, "z", 1);
		write(1, "\n", 1);
		return (0);
	}
	while (argv[i])
	{
		j = 0;
		while(argv[i][j])
		{
			if (argv[i][j] == 'z')
			{
				write(1, "z", 1);
				write(1, "\n", 1);
				return (0);
			}
			else
			{
				write(1, "z", 1);
				write(1, "\n", 1);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (0);
}