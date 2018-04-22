/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 20:37:12 by hlely             #+#    #+#             */
/*   Updated: 2017/11/09 11:23:53 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t				i;
	const unsigned char	*st1;
	const unsigned char	*st2;

	if (n == 0)
		return (0);
	i = 0;
	st1 = str1;
	st2 = str2;
	while (st1[i] == st2[i] && i < n - 1)
		i++;
	return (st1[i] - st2[i]);
}
