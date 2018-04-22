/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:35:38 by hlely             #+#    #+#             */
/*   Updated: 2017/11/08 16:42:34 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*tmp;
	char	*res;

	if (s)
	{
		i = 0;
		tmp = (char*)s;
		if ((res = ft_strnew(ft_strlen(tmp))))
		{
			while (s[i])
			{
				res[i] = f(s[i]);
				i++;
			}
			return (res);
		}
	}
	return (NULL);
}
