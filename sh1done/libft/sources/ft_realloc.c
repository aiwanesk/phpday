/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/18 12:01:40 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/06/18 12:01:41 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_realloc(char *old, int size)
{
	int		i;
	char	*new;

	i = 0;
	if ((new = malloc(sizeof(*new) * (ft_strlen(old) + size))) == NULL)
		return (NULL);
	while (old[i])
	{
		new[i] = old[i];
		i++;
	}
	free(old);
	return (new);
}
