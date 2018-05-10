/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_pro.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 14:36:41 by hlely             #+#    #+#             */
/*   Updated: 2018/05/10 21:11:55 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point			**shift_iso(t_data data, t_point **map)
{
	int		i;
	int		j;

	i = 0;
	while (i < data.y)
	{
		j = 0;
		while (j < data.x)
		{
			map[i][j].x = map[i][j].x + ft_abs(data.xmin);
			map[i][j].y = map[i][j].y + ft_abs(data.ymin);
			j++;
		}
		i++;
	}
	return (map);
}

t_point			**shift_point(t_data data, t_point **map)
{
	int		i;
	int		j;

	i = 0;
	while (i < data.y)
	{
		j = 0;
		while (j < data.x)
		{
			
			map[i][j].x += 300 + ((double)j / data.x) * data.zoom;
			map[i][j].y += 25 + ((double)i / data.y) * data.zoom;
			j++;
		}
		i++;
	}
	return (map);
}

t_point			iso_calc(t_point point, t_data *data)
{
	double		x;
	double		y;
	t_point		new;

	x = point.x;
	y = point.y;
	new.z = point.z * data->mod;
	new.x = (point.x - point.y) * data.xrot;
	new.y = (x + data.yrot * y) - new.z;
	data->xmin = (new.x < data->xmin) ? new.x : data->xmin;
	data->xmax = (new.x > data->xmax) ? new.x : data->xmax;
	data->ymin = (new.y < data->ymin) ? new.y : data->ymin;
	data->ymax = (new.y > data->ymax) ? new.y : data->ymax;
	data->zmax = (new.z > data->zmax) ? new.z : data->zmax;
	return (new);
}

t_point			**iso_pro(t_data *data, t_point **map)
{
	int			i;
	int			j;
	t_point		**iso;

	if (!(iso = ft_memalloc(sizeof(t_point*) * (data->y + 1))))
		exit(EXIT_FAILURE);
	i = 0;
	while (i < data->y)
	{
		if (!(iso[i] = ft_memalloc(sizeof(t_point) * (data->x + 1))))
			exit(EXIT_FAILURE);
		j = 0;
		while (j < data->x)
		{
			iso[i][j] = iso_calc(map[i][j], data);
			j++;
		}
		i++;
	}
	return (iso);
}
