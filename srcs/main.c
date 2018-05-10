/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 09:39:49 by hlely             #+#    #+#             */
/*   Updated: 2018/05/10 20:46:52 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		print_map(t_data data, t_point **map)
{
	int i;
	int j;

	i = 0;
	ft_printf("xmax : [%d]\nymax : [%d]\n", data.x, data.y);
	while (i < data.y)
	{
		j = 0;
		while (j < data.x)
		{
			ft_printf("[%2d|%2d|%2d]", (int)map[i][j].x, (int)map[i][j].y, (int)map[i][j].z);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

t_data		init_data(char *file)
{
	int			fd;
	t_data		data;

	if ((fd = open(file, O_RDONLY)) == -1)
		exit(EXIT_FAILURE);
	data.x = 0;
	data.y = 0;
	data.zmax = 0;
	data.mod = 1;
	data.zoom = 100;
	data.map = NULL;
	data.iso = NULL;
	data = get_nb_line(fd, data);
	close(fd);
	return (data);
}

int			main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (1);
	ft_printf("starting\n");
	data = init_data(av[1]);
	ft_printf("init_data DONE\n");
	data = init_map(av[1], data);
	ft_printf("init_map DONE\n");
	data.map = shift_point(data, data.map);
	ft_printf("shift_point DONE\n");
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 1000, 1000, "fdf");
	/* print_map(data, data.map); */
	data.iso = iso_pro(&data, data.map);
	/* data.iso = shift_iso(data, data.iso); */
	launch_render(data.iso, &data);
	return (0);
}
