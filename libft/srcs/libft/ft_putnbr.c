/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 20:35:53 by hlely             #+#    #+#             */
/*   Updated: 2017/11/09 16:34:11 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_print(char tab[])
{
	int		i;

	i = 0;
	while (tab[i] != '\n')
	{
		ft_putchar(tab[i] + 48);
		i++;
	}
}

static void	ft_putregular(int nb)
{
	int		i;
	int		n;
	char	nfinal[11];

	i = 0;
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-');
	}
	n = nb;
	while (n / 10 > 0)
	{
		i++;
		n = n / 10;
	}
	nfinal[i + 1] = '\n';
	while (i >= 0)
	{
		nfinal[i] = nb % 10;
		nb = nb / 10;
		i--;
	}
	ft_print(nfinal);
}

void		ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putregular(147483648);
	}
	else
		ft_putregular(nb);
}
