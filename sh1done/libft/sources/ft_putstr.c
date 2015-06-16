/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <aiwanesk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 20:19:37 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/02/11 20:19:38 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(const char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		ft_putstr("(NULL)");
	else if (s[0] == '\0')
		ft_putstr("NULL");
	else
	{
		while (s[i] != '\0')
			ft_putchar(s[i++]);
	}
}
