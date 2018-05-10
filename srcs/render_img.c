/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 15:03:54 by hlely             #+#    #+#             */
/*   Updated: 2018/05/10 18:37:00 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static unsigned int	*put_point_into_img(unsigned int *img, t_point **map,
		t_data data)
{
	int			i;
	int			j;
	t_draw		draw;

	i = 0;
	while (i < data.y)
	{
		j = 0;
		while (j < data.x)
		{
			img = ft_put_pixel(map[i][j].x, map[i][j].y, img, data);
			draw.xi = map[i][j].x;
			draw.yi = map[i][j].y;
			draw.i = i;
			draw.j = j;
			img = draw_seg_right(draw, img, map, data);
			img = draw_seg_down(draw, img, map, data);
			j++;
		}
		i++;
	}
	return (img);
}

static unsigned int	*calc_img(void *img_ptr, t_point **map, t_data data)
{
	unsigned int	*img;
	int				bpp;
	int				sl;
	int				en;

	img = (unsigned int*)mlx_get_data_addr(img_ptr, &bpp, &sl, &en);
	img = put_point_into_img(img, map, data);
	return (img);
}

void	launch_render(t_point **map, t_data *data)
{
	unsigned int	*img;

	data->img_ptr = mlx_new_image(data->mlx_ptr, 1000, 1000);
	img = calc_img(data->img_ptr, map, *data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	mlx_hook(data->win_ptr, 2, 3, key_event, data);
	mlx_loop(data->mlx_ptr);
}
