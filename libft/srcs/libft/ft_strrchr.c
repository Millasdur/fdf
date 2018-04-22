/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 10:34:45 by hlely             #+#    #+#             */
/*   Updated: 2017/11/08 15:28:28 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int i;
	int stat;

	i = 0;
	stat = -1;
	while (str[i])
	{
		if (str[i] == c)
			stat = i;
		i++;
	}
	if (str[i] == '\0' && c == '\0')
		return ((char*)&(str[i]));
	if (stat == -1)
		return (0);
	return ((char*)&(str[stat]));
}
