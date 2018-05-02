/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 14:17:16 by hlely             #+#    #+#             */
/*   Updated: 2018/04/25 10:48:04 by hlely            ###   ########.fr       */
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

t_point		iso_point(t_point src, t_data *data)
{
	double	x;
	double	y;
	t_point		dest;

	x = src.x;
	y = src.y;
	dest.z = src.z * data->modif;
	dest.x = (src.x - src.y) * 2;
	dest.y = (x + 1.5 * y) - dest.z;
	data->xmin = (dest.x < data->xmin) ? dest.x : data->xmin;
	data->ymin = (dest.y < data->ymin) ? dest.y : data->ymin;
	data->xmax = (dest.x > data->xmax) ? dest.x : data->xmax;
	data->ymax = (dest.y > data->ymax) ? dest.y : data->ymax;
	data->zmin = (dest.z < data->zmin) ? dest.z : data->zmin;
	data->zmax = (dest.z > data->zmax) ? dest.z : data->zmax;
	return (dest);
}

t_point		**iso_pro(t_point **tab, t_data *data)
{
	int		i;
	int		j;
	t_point	**res;

	i = 0;
	setup_data(tab, data);
	if (!(res = ft_memalloc(sizeof(t_point*) * (tab[0][0].y_max + 1))))
		return (NULL);
	while (tab[i])
	{
		if (!(res[i] = ft_memalloc(sizeof(t_point) * (tab[0][0].x_max + 1))))
			return (NULL);
		j = 0;
		while (j < tab[i][j].x_max)
		{
			res[i][j] = iso_point(tab[i][j], data);
			j++;
		}
		i++;
	}
	return (res);
}
