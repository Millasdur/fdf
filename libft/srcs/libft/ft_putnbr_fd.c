/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 21:15:31 by hlely             #+#    #+#             */
/*   Updated: 2017/11/09 09:20:49 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_print(char tab[], int fd)
{
	int i;

	i = 0;
	while (tab[i] != '\n')
	{
		ft_putchar_fd(tab[i] + 48, fd);
		i++;
	}
}

static void	ft_putregular(int nb, int fd)
{
	int		i;
	int		n;
	char	nfinal[11];

	i = 0;
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar_fd('-', fd);
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
	ft_print(nfinal, fd);
}

void		ft_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		ft_putregular(147483648, fd);
	}
	else
		ft_putregular(nb, fd);
}
