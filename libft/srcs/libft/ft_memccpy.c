/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 19:40:38 by hlely             #+#    #+#             */
/*   Updated: 2017/11/08 13:55:27 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *str1, const void *str2, int c, size_t n)
{
	size_t		i;
	char		*dest;
	char		*src;

	i = 0;
	dest = (char*)str1;
	src = (char*)str2;
	while (i < n)
	{
		dest[i] = src[i];
		if (src[i] == c)
			return (&(dest[i + 1]));
		i++;
	}
	return (NULL);
}
