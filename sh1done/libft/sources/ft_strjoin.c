/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <aiwanesk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 20:22:12 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/02/11 20:22:13 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*strc;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	strc = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (strc == NULL)
		return (NULL);
	ft_strcat(strc, s1);
	ft_strcat((strc + ft_strlen(s1)), s2);
	return (strc);
}
