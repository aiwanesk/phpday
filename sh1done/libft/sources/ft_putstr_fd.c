/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <aiwanesk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 20:19:56 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/02/11 20:19:57 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	int	i;

	i = 0;
	if (s == NULL || s[0] == '\0')
		ft_putstr_fd("(NULL)", fd);
	else
	{
		while (s[i] != '\0')
			ft_putchar_fd(s[i++], fd);
	}
}
