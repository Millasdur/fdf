/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 10:41:47 by hlely             #+#    #+#             */
/*   Updated: 2017/11/09 09:19:27 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *tofind)
{
	int i;
	int j;

	i = 0;
	if (tofind[0] == '\0')
		return ((char*)str);
	while (str[i])
	{
		j = 0;
		while (str[i + j] && tofind[j] && str[i + j] == tofind[j])
		{
			j++;
			if (tofind[j] == '\0')
				return ((char*)&(str[i]));
		}
		i++;
	}
	return (0);
}
