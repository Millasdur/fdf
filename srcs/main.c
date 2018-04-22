/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 13:31:51 by hlely             #+#    #+#             */
/*   Updated: 2018/04/22 16:42:04 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img;
	int		bpp;
	int		sl;
	int		en;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 200, 200, "fdf");
	img_ptr = mlx_new_image(mlx_ptr, 200, 200);
	img = mlx_get_data_addr(img_ptr, &bpp, &sl, &en);
	img[80000] = 127;
	img[80001] = 127;
	img[80002] = 127;
	mlx_put_image_to_window(NULL, win_ptr, img_ptr, 0, 0);
	mlx_loop(mlx_ptr);
	return (0);
}
