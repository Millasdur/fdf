/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:34:06 by hlely             #+#    #+#             */
/*   Updated: 2017/11/09 17:36:21 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_issort(int *tab, int length, int (*f)(int, int))
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (length <= 2)
		return (1);
	else
	{
		while (f(tab[i], tab[i + 1]) <= 0 && i < length - 1)
			i++;
		while (f(tab[j], tab[j + 1]) >= 0 && j < length - 1)
			j++;
		if (i != length - 1 && j != length - 1)
			return (0);
		return (1);
	}
}
