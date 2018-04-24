/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 14:17:16 by hlely             #+#    #+#             */
/*   Updated: 2018/04/24 16:46:57 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		**shift_tab(t_point **tab, t_data *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	data->xmin = (data->xmin < 0) ? -data->xmin : data->xmin;
	while (tab[i])
	{
		j = 0;
		while (j < tab[i][j].x_max)
		{
			tab[i][j].x = (tab[i][j].x + data->xmin + 1) *
				(((double)1000 - data->dx) / (data->dx));
			tab[i][j].y = (tab[i][j].y + 1) *
				(((double)1000 - data->dx) / (data->dx));
			j++;
		}
		i++;
	}
	return (tab);
}

void		setup_data(t_point **tab, t_data *data)
{
	if (tab && tab[0])
	{
		data->xmin = tab[0][0].x;
		data->xmax = tab[0][0].x;
		data->ymin = tab[0][0].y;
		data->ymax = tab[0][0].y;
		data->zmin = tab[0][0].z;
		data->zmax = tab[0][0].z;
	}
}

t_point		**iso_pro(t_point **tab, t_data *data)
{
	int		i;
	int		j;
	double	x;
	double	y;

	i = 0;
	setup_data(tab, data);
	while (tab[i])
	{
		j = 0;
		while (j < tab[i][j].x_max)
		{
			x = tab[i][j].x;
			y = tab[i][j].y;
			tab[i][j].z *= data->modif;
			tab[i][j].x = (tab[i][j].x - tab[i][j].y) * 2;
			tab[i][j].y = (x + 1.5 * y) - tab[i][j].z;
			data->xmin = (tab[i][j].x < data->xmin) ? tab[i][j].x : data->xmin;
			data->ymin = (tab[i][j].y < data->ymin) ? tab[i][j].y : data->ymin;
			data->xmax = (tab[i][j].x > data->xmax) ? tab[i][j].x : data->xmax;
			data->ymax = (tab[i][j].y > data->ymax) ? tab[i][j].y : data->ymax;
			data->zmin = (tab[i][j].z < data->zmin) ? tab[i][j].z : data->zmin;
			data->zmax = (tab[i][j].z > data->zmax) ? tab[i][j].z : data->zmax;
			j++;
		}
		i++;
	}
	return (tab);
}
