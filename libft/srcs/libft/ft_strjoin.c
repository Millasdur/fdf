/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:52:05 by hlely             #+#    #+#             */
/*   Updated: 2018/04/19 15:23:52 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	char	*res;

	if (s1 && s2)
	{
		size = ft_strlen(s1) + ft_strlen(s2);
		if ((res = ft_strnew(size)))
		{
			res = ft_strcat(res, s1);
			res = ft_strcat(res, s2);
			return (res);
		}
	}
	return (NULL);
}
