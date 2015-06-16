/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/01 18:08:34 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/06/04 15:13:57 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_entierpart(float a, int fd)
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
		ft_putnbr_fd(i, fd);
		a = a / 10;
	}
	ft_putchar_fd('.', fd);
}

void	ft_putfloat_fd(float a, int prec, int fd)
{
	int		i;

	if (a < 0)
	{
		a = -a;
		ft_putchar_fd('-', fd);
	}
	ft_entierpart(a, fd);
	i = 0;
	a = a - (int)a;
	while (i <= prec)
	{
		a = a * 10;
		ft_putnbr_fd(a, fd);
		i++;
	}
	ft_putchar_fd('\n', fd);
}
