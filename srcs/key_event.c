/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 10:02:52 by hlely             #+#    #+#             */
/*   Updated: 2018/05/11 11:33:23 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	inc_mod(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	data->mod += 0.1;
	clean_map(*data, &data->iso);
	data->iso = iso_pro(data, data->map);
	launch_render(data->iso, data);
}

void	dec_mod(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	data->mod -= 0.1;
	clean_map(*data, &data->iso);
	data->iso = iso_pro(data, data->map);
	launch_render(data->iso, data);
}

int		key_event(int key, t_data *data)
{
	if (key == EXIT)
		exit(EXIT_SUCCESS);
	if (key == INC)
		inc_mod(data);
	else if (key == DEC)
		dec_mod(data);
	else if (key == UP)
		move_x(data, -2);
	else if (key == DOWN)
		move_x(data, 2);
	else if (key == RIGHT)
		move_y(data, -2);
	else if (key == LEFT)
		move_y(data, 2);
	else if (key == M)
		zoom_in_out(data, 1);
	else if (key == L)
		zoom_in_out(data, -1);
	return (0);
}
