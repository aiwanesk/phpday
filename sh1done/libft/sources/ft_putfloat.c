/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/01 17:59:50 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/06/04 15:13:50 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_entierpart(float a)
{
	int		i;

	while (a > 1)
	{
		a = a / 10;
		i = a;
		a = a * 10;
		i = a - i;
		while (i > 10)
			i /= 10;
		ft_putnbr(i);
		a = a / 10;
	}
	ft_putchar('.');
}

void	ft_putfloat(float a, int prec)
{
	int		i;

	if (a < 0)
	{
		a = -a;
		ft_putchar('-');
	}
	ft_entierpart(a);
	i = 0;
	a = a - (int)a;
	while (i <= prec)
	{
		a = a * 10;
		ft_putnbr(a);
		i++;
	}
	ft_putchar('\n');
}
