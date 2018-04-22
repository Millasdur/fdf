/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 16:03:26 by hlely             #+#    #+#             */
/*   Updated: 2018/04/18 15:41:06 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_n(intmax_t value, int base)
{
	int i;

	i = 0;
	if (value < 0 && (intmax_t)base == 10)
		i++;
	while (value != 0)
	{
		value /= base;
		i++;
	}
	return (i);
}

char		*ft_itoa_base(intmax_t value, int base)
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
	if (value < 0 && base == 10)
		res[0] = '-';
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
