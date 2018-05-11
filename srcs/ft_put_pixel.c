/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 12:47:36 by hlely             #+#    #+#             */
/*   Updated: 2018/05/11 11:43:03 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int	*ft_put_pixel(t_draw draw, unsigned int *img,
		t_data data, t_point map)
{
	int		color;

	(void)data;
	color = 0xFFFFFF;
	if (draw.x > 0 && draw.x < 1000 && draw.y > 0 && draw.y < 1000)
	{
		if (map.z == 0)
			img[draw.y * 1000 + draw.x] = color;
		else if (map.z > 0)
			img[draw.y * 1000 + draw.x] = 0xFF0000;
		else
			img[draw.y * 1000 + draw.x] = 0x0000FF;
	}
	return (img);
}
