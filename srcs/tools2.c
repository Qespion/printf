/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 17:33:37 by oespion           #+#    #+#             */
/*   Updated: 2018/05/17 18:09:16 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.a"
#include <stdio.h>

void	call_va(t_list *p)
{
	uintmax_t		max;
	long long int	longlong;
	int				basenb;
	short			bermuda;
	unsigned char	inconnu;

	if (p->j)
	{
		max = va_arg(p->ap, uintmax_t);
		p->nbout += ft_int_len(max_nbr);
		ft_putnbrnu(p, (unsigned long long)max)
	}
	else if (p->l || p->ll || p->z)
	{
		if (p->blank == 1 && p->positive == 0 && nbr > 0)
		{
			ft_putchar(' ');
			p->width--;
			p->nbout++;
		}
		longlong = va_arg(p->ap, long long);
		p->nbout += longlong_len(nbr);
		if (p->positive && longlong >= 0)
		{
			p->nbout++;
			ft_putchar('+');
		}
		nbr <= 0 ? p->nbout++ : 0;
		printfnb(t_list *p, longlong, 0, 0);
	}
	else if (p->h)
	{
		bermuda = va_arg(p->ap, short);
		p->nbout += longlong_len(nbr);
		printfnb(t_list *p, (long long)bermuda, 0, 0);
	}
	else if (p->hh)
	{
		inconnu = va_arg(p->ap, unsigned char);
		p->nbout += longlong_len(nbr);
		printfnb(t_list *p, (long long)inconnu, 0, 0);
	}
	else
	{
		basenb = va_arg(p->ap, uintmax_t);
		p->nbout += longlong_len(nbr);
		printfnb(t_list *p, (long long)basenb, 0, 0);
	}
}
