/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <aiwanesk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 20:14:14 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/02/11 20:14:17 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isnum(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	else
		return (0);
}
