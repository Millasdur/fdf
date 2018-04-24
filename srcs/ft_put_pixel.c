/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 12:47:36 by hlely             #+#    #+#             */
/*   Updated: 2018/04/24 16:45:49 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int	*ft_put_pixel(int x, int y, unsigned int *img, t_data data)
{
	data.xmin = (data.xmin < 0) ? -data.xmin : data.xmin;
	data.dx = (data.dx < 0) ? -data.dx : data.dx;
	/* x = (x + data.xmin + 1) * ((1000 - data.dx) / data.dx); */
	/* y = (y + 1) * ((1000 - data.dx) / data.dx); */
	/* printf("{%d, %d}", x, y); */
	(void)data;
	if (x > 0 && x < 1000 && y > 0 && y < 1000)
		img[y * 1000 + x] = 0xFFFFFF;
	return (img);
}
