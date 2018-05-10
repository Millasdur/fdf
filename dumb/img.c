/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 14:23:20 by hlely             #+#    #+#             */
/*   Updated: 2018/05/09 09:18:29 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static unsigned int	*draw1(t_draw draw, unsigned int *img,
		t_point **tab, t_data data)
{
	int		k;
	int		x;
	int		y;

	(void)tab;
	k = 1;
	x = draw.xi;
	y = draw.yi;
	draw.sum = draw.dx / 2;
	while (k <= draw.dx)
	{
		x += draw.x_inc;
		draw.sum += draw.dy;
		if (draw.sum >= draw.dx)
		{
			draw.sum -= draw.dx;
			y += draw.y_inc;
		}
		img = ft_put_pixel(x, y, img, data);
		/* img[y * 1000 + x] = 0xFFFFFF; */
		k++;
	}
	return (img);
}

static unsigned int	*draw2(t_draw draw, unsigned int *img, t_point **tab,
		t_data data)
{
	int		k;
	int		x;
	int		y;

	(void)tab;
	k = 1;
	x = draw.xi;
	y = draw.yi;
	draw.sum = draw.dy / 2;
	while (k <= draw.dy)
	{
		y += draw.y_inc;
		draw.sum += draw.dx;
		if (draw.sum >= draw.dy)
		{
			draw.sum -= draw.dy;
			x += draw.x_inc;;
		}
		img = ft_put_pixel(x, y, img, data);
		/* img[y * 1000 + x] = 0xFFFFFF; */
		k++;
	}
	return (img);
}

static unsigned int	*draw_seg_right(t_draw draw, unsigned int *img,
		t_point **tab, t_data data)
{
	if (!tab[draw.i] || draw.j == tab[draw.i][draw.j].x_max - 1)
		return (img);
	draw.xf = tab[draw.i][draw.j + 1].x;
	draw.yf = tab[draw.i][draw.j + 1].y;
	draw.dx = draw.xf - draw.xi;
	draw.dy = draw.yf - draw.yi;
	draw.x_inc = (draw.dx > 0) ? 1 : -1;
	draw.y_inc = (draw.dy > 0) ? 1 : -1;
	draw.dx = ft_abs(draw.dx);
	draw.dy = ft_abs(draw.dy);
	if (draw.dx > draw.dy)
		img = draw1(draw, img, tab, data);
	else
		img = draw2(draw, img, tab, data);
	return (img);
}

static unsigned int	*draw_seg_down(t_draw draw, unsigned int *img,
		t_point **tab, t_data data)
{
	if (!tab[draw.i + 1] || draw.j == tab[draw.i][draw.j].x_max)
		return (img);
	draw.xf = tab[draw.i + 1][draw.j].x;
	draw.yf = tab[draw.i + 1][draw.j].y;
	draw.dx = draw.xf - draw.xi;
	draw.dy = draw.yf - draw.yi;
	draw.x_inc = (draw.dx > 0) ? 1 : -1;
	draw.y_inc = (draw.dy > 0) ? 1 : -1;
	draw.dx = ft_abs(draw.dx);
	draw.dy = ft_abs(draw.dy);
	if (draw.dx > draw.dy)
		img = draw1(draw, img, tab, data);
	else
		img = draw2(draw, img, tab, data);
	return (img);
}

static unsigned int	*put_point_into_img(unsigned int *img, t_point **tab,
		t_data data)
{
	int		i;
	int		j;
	t_draw	draw;

	i = 0;
	data.xmin = (data.xmin < 0) ? -data.xmin : data.xmin;
	if (tab && tab[i])
	{
		tab[i][0].x = (tab[i][0].x + data.xmin + 1) *
			(((double)1000 - data.dx) / (data.dx));
		tab[i][0].y = (tab[i][0].y + 1) *
			(((double)1000 - data.dx) / (data.dx));
	}
	printf("[%d]\n", tab[0][0].x_max);
	while (tab && tab[i] && tab[i + 1])
	{
		j = 0;
		while (j < tab[i][j].x_max + 1)
		{
			if (i == 0)
			{
				tab[i][j + 1].x = (tab[i][j + 1].x + data.xmin + 1) *
					(((double)1000 - data.dx) / (data.dx));
				tab[i][j + 1].y = (tab[i][j + 1].y + 1) *
					(((double)1000 - data.dx) / (data.dx));
			}
			tab[i + 1][j].x = (tab[i + 1][j].x + data.xmin + 1) *
				(((double)1000 - data.dx) / (data.dx));
			tab[i + 1][j].y = (tab[i + 1][j].y + 1) *
				(((double)1000 - data.dx) / (data.dx));
			img = ft_put_pixel(tab[i][j].x, tab[i][j].y, img, data);
			draw.xi = tab[i][j].x;
			draw.yi = tab[i][j].y;
			draw.i = i;
			draw.j = j;
			img = draw_seg_right(draw, img, tab, data);
			img = draw_seg_down(draw, img, tab, data);
			j++;
		}
		i++;
	}
	return (img);
}

static unsigned int	*calc_img(void *img_ptr, t_point **tab, t_data data)
{
	unsigned int	*img;
	int				bpp;
	int				sl;
	int				en;

	img = (unsigned int*)mlx_get_data_addr(img_ptr, &bpp, &sl, &en);
	img = put_point_into_img(img, tab, data);
	return (img);
}

void	launch_render(t_point **tab, t_data *data)
{
	void			*img_ptr;
	unsigned int	*img;

	img_ptr = mlx_new_image(data->mlx_ptr, 1000, 1000);
	data->img_ptr = img_ptr;
	img = calc_img(img_ptr, tab, *data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img_ptr, 0, 0);
	mlx_hook(data->win_ptr, 2, 3, key_event, data);
	mlx_loop(data->mlx_ptr);
}
