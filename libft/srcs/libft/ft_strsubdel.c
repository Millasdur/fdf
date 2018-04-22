/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 18:48:59 by hlely             #+#    #+#             */
/*   Updated: 2018/04/17 18:49:09 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsubdel(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;

	if (s)
	{
		i = 0;
		if ((res = ft_strnew(len)))
		{
			while (i < len)
			{
				res[i] = s[start + i];
				i++;
			}
			ft_strdel(&s);
			return (res);
		}
	}
	return (NULL);
}
