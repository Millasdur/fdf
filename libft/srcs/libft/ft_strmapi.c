/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:55:56 by hlely             #+#    #+#             */
/*   Updated: 2017/11/08 16:45:31 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*tmp;
	char			*res;

	if (s)
	{
		i = 0;
		tmp = (char*)s;
		if ((res = ft_strnew(ft_strlen(tmp))))
		{
			while (s[i])
			{
				res[i] = f(i, s[i]);
				i++;
			}
			return (res);
		}
		return (NULL);
	}
	else
		return (NULL);
}
