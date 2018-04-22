/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinddel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:22:43 by hlely             #+#    #+#             */
/*   Updated: 2018/04/21 17:06:50 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinddel(char *s1, char *s2)
{
	int		size;
	char	*res;

	if (s1 && s2)
	{
		size = ft_strlen(s1) + ft_strlen(s2);
		res = ft_strnew(size);
		if (res)
		{
			res = ft_strcat(res, s1);
			ft_strdel(&s1);
			res = ft_strcat(res, s2);
			ft_strdel(&s2);
			return (res);
		}
	}
	if (!s1 && s2)
	{
		res = ft_strdup(s2);
		ft_strdel(&s2);
		return (res);
	}
	return (NULL);
}

char	*ft_strnjoinddel(char *s1, char *s2, int len1, int len2)
{
	int		size;
	char	*res;

	size = len1 + len2;
	res = (char*)malloc(sizeof(char) * (size + 1));
	if (res)
	{
		res = ft_ncat(res, s1, 0, len1);
		ft_strdel(&s1);
		res = ft_ncat(res, s2, len1, len2);
		ft_strdel(&s2);
		return (res);
	}
	return (NULL);
}
