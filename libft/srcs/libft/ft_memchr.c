/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 20:03:54 by hlely             #+#    #+#             */
/*   Updated: 2017/11/09 14:47:39 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t				i;
	const char			*tmp;

	i = 0;
	tmp = str;
	while (i < n)
	{
		if ((unsigned char)(tmp[i]) == (unsigned char)c)
			return ((char*)&(str[i]));
		i++;
	}
	return (NULL);
}
