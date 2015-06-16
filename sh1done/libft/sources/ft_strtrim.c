/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <aiwanesk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 20:24:35 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/02/11 20:24:36 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		len;
	int		i;
	char	*s1;

	i = 0;
	if (!s)
		return (NULL);
	while (ft_isspace(*s) && *s)
		s++;
	len = ft_strlen(s);
	while (s[i])
		i++;
	i--;
	while (ft_isspace(s[i]) && i >= 0 && *s)
	{
		len--;
		i--;
	}
	if (!(s1 = ft_strnew(len + 1)))
		return (NULL);
	ft_strncpy(s1, s, (len));
	s1[len + i] = '\0';
	return (s1);
}
