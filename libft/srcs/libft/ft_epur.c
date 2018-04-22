/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_epur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 11:57:28 by hlely             #+#    #+#             */
/*   Updated: 2018/01/11 12:01:14 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_epur(char *line, char c)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] == c)
			j++;
	}
	res = ft_strnew(ft_strlen(line) - j);
	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] == c)
		{
			res[j] = line[i];
			j++;
		}
		i++;
	}
	return (res);
}
