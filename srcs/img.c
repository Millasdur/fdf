/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 14:23:20 by hlely             #+#    #+#             */
/*   Updated: 2018/04/23 18:33:23 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static unsigned int	*draw_seg(unsigned int *img, t_point **tab)
{

}

static unsigned int	*put_point_into_img(unsigned int *img, t_point **tab)
{
	int		i;
	int		j;

	i = 0;
	while (tab && tab[i])
	{
		j = 0;
		while (j < tab[i][j].x_max)
		{
			img[((int)tab[i][j].y * 1000) + (int)tab[i][j].x] = 0xFFFFFF;
			img = draw_seg(img, tab);
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
