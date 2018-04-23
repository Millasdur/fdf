/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 14:17:16 by hlely             #+#    #+#             */
/*   Updated: 2018/04/23 18:07:16 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		**shift_tab(t_point **tab)
{
	int		i;
	int		j;
	double	modif;

	i = 0;
	j = 0;
	modif = 10;
	while (tab[i])
	{
		j = 0;
		while (j < tab[i][j].x_max)
		{
			tab[i][j].x = tab[i][j].x +
				(1000 - tab[i][j].x_max * modif) / 2 + modif * j;
			tab[i][j].y = tab[i][j].y +
				(1000 - tab[i][j].y_max * modif) / 2 + modif * (i + j);
			tab[i][j].z = tab[i][j].z + modif * 5;
			j++;
		}
		i++;
	}
	return (tab);
}

t_point		**iso_pro(t_point **tab)
{
	int		i;
	int		j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (j < tab[i][j].x_max)
		{
			tab[i][j].x = (tab[i][j].x - tab[i][j].y) * 2;
			tab[i][j].y = (tab[i][j].x + tab[i][j].y) - tab[i][j].z;
			j++;
		}
		i++;
	}
	return (tab);
}
