/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:37:04 by hlely             #+#    #+#             */
/*   Updated: 2018/04/17 18:48:54 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
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
			return (res);
		}
	}
	return (NULL);
}
