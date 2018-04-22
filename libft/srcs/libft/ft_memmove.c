/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 19:48:21 by hlely             #+#    #+#             */
/*   Updated: 2017/11/08 14:02:05 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	size_t		i;
	char		*dest;
	const char	*src;
	char		tmp[n];

	i = 0;
	dest = str1;
	src = str2;
	if (n > 100000000)
		return (0);
	while (i < n)
	{
		tmp[i] = src[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		dest[i] = tmp[i];
		i++;
	}
	return (dest);
}
