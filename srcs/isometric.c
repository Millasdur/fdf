/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 14:17:16 by hlely             #+#    #+#             */
/*   Updated: 2018/04/24 11:50:40 by hlely            ###   ########.fr       */
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
	modif = 2;
	while (tab[i])
	{
		j = 0;
		while (j < tab[i][j].x_max)
		{
			tab[i][j].x = (tab[i][j].x + tab[i][j].x_max + 1) * tab[i][j].x_max;
			tab[i][j].y = (tab[i][j].y + tab[i][j].y_max + 1) * tab[i][j].x_max;
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
	double	x;
	double	y;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (j < tab[i][j].x_max)
		{
			x = tab[i][j].x;
			y = tab[i][j].y;
			tab[i][j].z *= tab[i][j].modif;
			tab[i][j].x = (tab[i][j].x - tab[i][j].y) * 2;
			tab[i][j].y = (x + 1.5 * y) - tab[i][j].z;
			j++;
		}
		i++;
	}
	return (tab);
}
