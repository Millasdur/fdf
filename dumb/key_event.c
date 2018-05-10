/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 10:02:52 by hlely             #+#    #+#             */
/*   Updated: 2018/04/25 10:34:58 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int		key_event(int key, t_data *data)
{
	t_point	**tmp;

	if (key == 53)
		exit(EXIT_SUCCESS);
	if (key == 69) //+
	{
		printf("THEN:%d\n", (int)data->saved[0][0].x);
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
		data->modif += 0.1;
		tmp = data->saved;
		data->tab = iso_pro(tmp, data);
		launch_render(data->tab, data);
	}
	/* if (key == 78) //- */
	return (0);
}
