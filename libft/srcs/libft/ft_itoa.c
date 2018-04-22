/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 19:19:34 by hlely             #+#    #+#             */
/*   Updated: 2017/11/09 14:37:57 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	resu(int n, char **res, int div, int neg)
{
	(*res)[div] = '\0';
	while (n > 0)
	{
		(*res)[div - neg - 1] = n % 10 + 48;
		n = n / 10;
		div--;
	}
	if (neg)
		(*res)[0] = '-';
}

static char	*check(int n)
{
	char	*res;

	if (n == 0)
	{
		res = ft_strnew(1);
		res = ft_strcpy(res, "0");
	}
	else
	{
		res = ft_strnew(12);
		res = ft_strcpy(res, "-2147483648");
	}
	return (res);
}

char		*ft_itoa(int n)
{
	int		div;
	int		tmp;
	int		neg;
	char	*res;

	div = 0;
	neg = 0;
	if (n == 0 || n == -2147483648)
		return (check(n));
	if (n < 0)
	{
		neg = -1;
		n = -n;
	}
	tmp = n;
	while (tmp > 0)
	{
		div++;
		tmp = tmp / 10;
	}
	if ((res = ft_strnew(div + 1)))
		resu(n, &res, div, neg);
	return (res);
}
