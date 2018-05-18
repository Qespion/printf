/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printable_adv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 12:34:52 by oespion           #+#    #+#             */
/*   Updated: 2018/05/18 17:45:58 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

void	printbinary(t_list *p)
{
	char	*bin;
	unsigned int str;

	str = va_arg(p->ap, unsigned int);
	bin = ft_convert_base(str, 2);
	if (p->precision != -1 || p->width != -1)
		ft_putstrn(p, bin);
	else
	{
		p->nbout += ft_strlen(bin);
		ft_putstr(bin);
	}
	free(bin);
}

void	printhexa(t_list *p, int maj)
{
	char		*hexa;
	void		*enb;
	int			ng;

	hexa = "0";
	enb = va_arg(p->ap, void*);
	ng = (int)enb;
	if ((((uintmax_t)enb <= 2147483648)
			|| (p->l) || p->ll || p->j) && ng >= -1)
		hexa = ft_convert_base((uintmax_t)enb, 16);
	if (ng < -1)
	{
		ng = 2147483648 - ft_abs(ng);
		hexa = ft_convert_base_int(ng, 16);
		hexa[0] = 'f';
	}
	maj ? hexa = ft_toupper(hexa) : 0;
	!*hexa ? hexa = "0" : 0;
	if (*hexa == '0' && p->precision == 0)
	{
		p->width++;
		ft_gwidth(hexa, p, 0);
		return ;
	}
	if (p->precision != -1 || p->width != -1)
		ft_puthexan(p, hexa, 0, maj);
	else
	{
		p->nbout += 2 +ft_strlen(hexa);
		if (maj)
			p->sharp && *hexa != '0'? ft_putstr("0X") : p->nbout--;
		else
			p->sharp && *hexa != '0'? ft_putstr("0x") : p->nbout--;
		p->sharp && *hexa != '0'? 0 : p->nbout-- ;
		ft_putstr(hexa);
	};
}

void	printoctal(t_list *p, int maj)
{
	char		*hexa;
	void		*nb;
	int			ng;

	nb = va_arg(p->ap, void*);
	ng = (int)nb;
	p->width == -1 && p->precision == 0 && nb == 0 ? p->nbout-- : 0;
	if ((((uintmax_t)nb <= 2147483648)
			|| (p->l) || p->ll) && ng >= -1)
		hexa = ft_convert_base((uintmax_t)nb, 8);
	if (ng < -1)
	{
		ng = 2147483648 - ft_abs(ng);
		hexa = ft_convert_base_int(ng, 16);
		hexa[0] = 'f';
	}
	maj ? hexa = ft_toupper(hexa) : 0;
	!*hexa ? hexa = "0" : 0;
	if (p->precision != -1 || p->width != -1)
	{
		p->sharp ? p->nbout-- : 0;
		ft_puthexan(p, hexa, 1, maj);
	}
	else
	{
		p->sharp ? ft_putstr("0") : p->nbout-- ;
		p->nbout += 1 +ft_strlen(hexa);
		ft_putstr(hexa);
	}
}

void	printunsigned(t_list *p, int maj)
{
	unsigned long long nbr;

	nbr = va_arg(p->ap, unsigned long long);
	(void)maj;
	if (nbr > 4294967295 && !p->ll && !p->l && !maj && !p->j)
		nbr = 0;
	nbr == 0 ? p->nbout++ : 0;
	if (p->positive && p->width != -1)
		p->width--;
	if (p->precision != -1 || p->width != -1)
		ft_putnbrnu(p, nbr);
	else
	{
		if ((((nbr > 2147483648 && !p->l) && (nbr > 4294967295 && !p->ll)) || !maj))
			p->nbout += int_len(nbr, 10);
		else
			p->nbout++;
		ft_putnbru(nbr);
	}
}

void	printchar(t_list *p, char letter)
{
	char c;
	if (letter != '%')
		c = va_arg(p->ap, int);
	if ((p->precision != -1 || p->width != -1)
			&& letter == '%')
		ft_putcharnf(p);
	else if (p->precision != -1 || p->width != -1)
	{
		ft_putcharn(p, c);
	}
	else
	{
		if (letter == '%')
			ft_putchar('%');
		if (letter != '%')
		{
			p->nbout++;
			ft_putchar(c);
		}
	}
}
