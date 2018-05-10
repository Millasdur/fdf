/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 20:34:10 by hlely             #+#    #+#             */
/*   Updated: 2018/05/10 21:19:03 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		shift_x(t_data *data, int x)
{
	int		i;
	int		j;

	i = 0;
	while (i < data->y)
	{
		j = 0;
		while (j < data->x)
		{
			data->map[i][j].x += x;
			j++;
		}
		i++;
	}
}

void		shift_y(t_data *data, int y)
{
	int		i;
	int		j;

	i = 0;
	while (i < data->y)
	{
		j = 0;
		while (j < data->x)
		{
			data->map[i][j].y += y;
			j++;
		}
		i++;
	}
}

void		zoom(t_data *data, int z)
{
	int		i;
	int		j;

	i = 0;
	while (i < data->y)
	{
		j = 0;
		while (j < data->x)
		{
			data->map[i][j].x += z * ((double)j / data->x) * 10;
			data->map[i][j].y += z * ((double)i / data->y) * 10;
			j++;
		}
		i++;
	}
}
