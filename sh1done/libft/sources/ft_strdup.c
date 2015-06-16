/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <aiwanesk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 20:21:18 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/02/11 20:21:24 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*s2;

	if (!s1)
		return (NULL);
	s2 = ft_strnew(ft_strlen(s1) + 1);
	if (s2 == NULL)
		return (NULL);
	ft_strncpy(s2, s1, ft_strlen(s1));
	return (s2);
}
