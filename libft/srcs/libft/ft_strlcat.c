/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 13:43:19 by hlely             #+#    #+#             */
/*   Updated: 2017/11/09 15:02:27 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	len;

	i = 0;
	if (n == 0)
		return (ft_strlen(dest));
	while (dest[i] && i < n)
		i++;
	len = i;
	while (src[i - len] && i < n - 1)
	{
		dest[i] = src[i - len];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (len + ft_strlen(src));
}
