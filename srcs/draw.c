/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 15:29:50 by hlely             #+#    #+#             */
/*   Updated: 2018/05/10 16:18:53 by hlely            ###   ########.fr       */
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
		k++;
	}
	return (img);
}

unsigned int		*draw_seg_right(t_draw draw, unsigned int *img,
		t_point **tab, t_data data)
{
	if (!tab[draw.i] || draw.j == data.x - 1)
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

unsigned int		*draw_seg_down(t_draw draw, unsigned int *img,
		t_point **tab, t_data data)
{
	if (draw.j == data.x || !tab[draw.i + 1])
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
