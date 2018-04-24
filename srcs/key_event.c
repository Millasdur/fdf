/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 10:02:52 by hlely             #+#    #+#             */
/*   Updated: 2018/04/24 16:49:52 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int		key_event(int key, t_data *data)
{
	if (key == 53)
		exit(EXIT_SUCCESS);
	if (key == 69) //+
	{
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
		data->modif += 0.1;
		printf("%f\n", data->modif);
		data->tab = iso_pro(data->saved, data);
		launch_render(data->tab, data);
	}
	/* if (key == 78) //- */
	return (0);
}
