/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthiry <gthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 14:38:42 by gthiry            #+#    #+#             */
/*   Updated: 2015/02/02 14:41:22 by gthiry           ###   ########.fr       */
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
