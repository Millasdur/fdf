/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 20:33:01 by hlely             #+#    #+#             */
/*   Updated: 2018/05/10 21:20:02 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		move_x(t_data *data, int x)
{
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	shift_x(data, x);
	clean_map(*data, &data->iso);
	data->iso = iso_pro(data, data->map);
	launch_render(data->iso, data);
}

void		move_y(t_data *data, int y)
{
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	shift_y(data, y);
	clean_map(*data, &data->iso);
	data->iso = iso_pro(data, data->map);
	launch_render(data->iso, data);
}

void		zoom_in_out(t_data *data, int z)
{
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	zoom(data, z);
	clean_map(*data, &data->iso);
	data->iso = iso_pro(data, data->map);
	launch_render(data->iso, data);
}

void		rotxy(t_data *data, double z)
{
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	data->xrot += z;
	data->yrot += z;
	clean_map(*data, &data->iso);
	data->iso = iso_pro(data, data->map);
	launch_render(data->iso, data);
}
