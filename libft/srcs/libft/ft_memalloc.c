/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:27:57 by hlely             #+#    #+#             */
/*   Updated: 2017/11/07 15:01:07 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*tab;
	size_t	i;

	i = 0;
	if (!(tab = (void*)malloc(size)))
		return (0);
	while (i < size)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}
