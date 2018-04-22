/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 12:55:49 by hlely             #+#    #+#             */
/*   Updated: 2018/04/18 15:40:10 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_n(uintmax_t value, int base)
{
	int i;

	i = 0;
	while (value != 0)
	{
		value /= base;
		i++;
	}
	return (i);
}

char		*ft_uitoa_base(uintmax_t value, int base)
{
	int		vv;
	char	*bb;
	char	*res;

	bb = "0123456789ABCDEF";
	if (value == 0)
		return (ft_strdup("0"));
	vv = nb_n(value, base);
	if (!(res = (char*)malloc(sizeof(char) * (vv + 1))))
		return (NULL);
	res[vv] = '\0';
	vv--;
	while (value)
	{
		res[vv] = bb[ft_abs(value % base)];
		vv--;
		value /= base;
	}
	return (res);
}
