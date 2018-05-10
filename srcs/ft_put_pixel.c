/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 12:47:36 by hlely             #+#    #+#             */
/*   Updated: 2018/05/10 21:32:17 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int	*ft_put_pixel(int x, int y, unsigned int *img, t_data data, t_point map)
{
	/* double	alt; */
	int		color;

	(void)data;
	(void)map;
	color = 0xFFFFFF;
	if (x > 0 && x < 1000 && y > 0 && y < 1000)
	{
		/* alt = (map.z - data.zmax) / 100; */
		/* alt = alt < 0 ? -alt : alt; */
		/* color = 255 + 255 * (16 * alt) + 65535 * (16 * alt); */
		/* printf("[%f|%#X]\n", alt, color); */
		if (map.z == 0)
			img[y * 1000 + x] = color;
		else if (map.z > 0)
			img[y * 1000 + x] = 0xFF0000;
		else
			img[y * 1000 + x] = 0x0000FF;
	}
	return (img);
}
