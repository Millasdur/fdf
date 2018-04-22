/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 19:29:43 by hlely             #+#    #+#             */
/*   Updated: 2017/11/07 21:44:59 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	size_t		i;
	char		*tmp1;
	const char	*tmp2;

	i = 0;
	tmp1 = str1;
	tmp2 = str2;
	while (i < n)
	{
		tmp1[i] = tmp2[i];
		i++;
	}
	return (str1);
}
