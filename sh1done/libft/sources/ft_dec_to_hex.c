/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/18 12:02:23 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/06/18 12:02:24 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		ft_hexa_nb(int n)
{
	if (n == 10)
		return ('A');
	else if (n == 11)
		return ('B');
	else if (n == 12)
		return ('C');
	else if (n == 13)
		return ('D');
	else if (n == 14)
		return ('E');
	else
		return ('F');
}

char			*ft_dec_to_hex(int n)
{
	char	*str;
	char	*hex;
	int		i;
	int		nb;

	i = 0;
	str = ft_itoa(n);
	hex = ft_strnew(ft_strlen(str));
	while (n > 0)
	{
		nb = (n % 16);
		if (nb >= 10)
			hex[i] = ft_hexa_nb(nb);
		else
			hex[i] = nb + '0';
		n /= 16;
		i++;
	}
	hex[i] = 0;
	ft_putstr(hex);
	ft_putchar('\n');
	hex = ft_strrev(hex);
	ft_putstr(hex);
	ft_putchar('\n');
	return (hex);
}
