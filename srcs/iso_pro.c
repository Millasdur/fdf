/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_pro.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 14:36:41 by hlely             #+#    #+#             */
/*   Updated: 2018/05/10 15:11:39 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point			iso_calc(t_point point, t_data data)
{
	double		x;
	double		y;
	t_point		new;

	x = point.x;
	y = point.y;
	new.z = point.z * data.mod;
	new.x = (point.x - point.y) * 2;
	new.y = (x + 1.5 * y) - new.z;
	return (new);
}

t_point			**iso_pro(t_data data, t_point **map)
{
	int			i;
	int			j;
	t_point		**iso;

	if (!(iso = ft_memalloc(sizeof(t_point*) * (data.y + 1))))
		exit(EXIT_FAILURE);
	i = 0;
	while (i < data.y)
	{
		if (!(iso[i] = ft_memalloc(sizeof(t_point) * (data.x + 1))))
			exit(EXIT_FAILURE);
		j = 0;
		while (j < data.x)
		{
			iso[i][j] = iso_calc(map[i][j], data);
			j++;
		}
		i++;
	}
	return (iso);
}
