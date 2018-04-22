/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 10:55:46 by hlely             #+#    #+#             */
/*   Updated: 2017/11/07 21:47:49 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *tofind, size_t len)
{
	int		i;
	int		j;
	size_t	count;

	i = 0;
	j = 0;
	count = 0;
	while (str[i] && count < len)
	{
		while (tofind[j] && count < len && str[i] == tofind[j])
		{
			i++;
			j++;
			count++;
		}
		if (!tofind[j])
			return ((char*)&(str[i - j]));
		else
		{
			i++;
			count = i;
		}
	}
	return (0);
}
