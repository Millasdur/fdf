/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 14:23:20 by hlely             #+#    #+#             */
/*   Updated: 2018/04/24 12:39:54 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static unsigned int	*draw1(t_draw draw, unsigned int *img, t_point **tab)
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
		img[y * 1000 + x] = 0xFFFFFF;
		k++;
	}
	return (img);
}

static unsigned int	*draw2(t_draw draw, unsigned int *img, t_point **tab)
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
		img[y * 1000 + x] = 0xFFFFFF;
		k++;
	}
	return (img);
}

static unsigned int	*draw_seg_right(t_draw draw, unsigned int *img, t_point **tab)
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
		img = draw1(draw, img, tab);
	else
		img = draw2(draw, img, tab);
	return (img);
}

static unsigned int	*draw_seg_down(t_draw draw, unsigned int *img, t_point **tab)
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
		img = draw1(draw, img, tab);
	else
		img = draw2(draw, img, tab);
	return (img);
}

static unsigned int	*put_point_into_img(unsigned int *img, t_point **tab)
{
	int		i;
	int		j;
	t_draw	draw;

	i = 0;
	while (tab && tab[i])
	{
		j = 0;
		while (j < tab[i][j].x_max)
		{
			img[((int)tab[i][j].y * 1000) + (int)tab[i][j].x] = 0xFFFFFF;
			draw.xi = tab[i][j].x;
			draw.yi = tab[i][j].y;
			draw.i = i;
			draw.j = j;
			img = draw_seg_right(draw, img, tab);
			img = draw_seg_down(draw, img, tab);
			j++;
		}
		i++;
	}
	return (img);
}

static unsigned int	*calc_img(void *img_ptr, t_point **tab)
{
	unsigned int	*img;
	int				bpp;
	int				sl;
	int				en;

	img = (unsigned int*)mlx_get_data_addr(img_ptr, &bpp, &sl, &en);
	img = put_point_into_img(img, tab);
	return (img);
}

void	launch_render(t_point **tab)
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	unsigned int	*img;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "fdf");
	img_ptr = mlx_new_image(mlx_ptr, 1000, 1000);
	img = calc_img(img_ptr, tab);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
	mlx_key_hook(win_ptr, key_event, NULL);
	mlx_loop(mlx_ptr);
}
