/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 09:39:49 by hlely             #+#    #+#             */
/*   Updated: 2018/05/11 13:34:20 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			param_error(void)
{
	ft_printf_fd(STDERR_FILENO, "Error with param name or number.");
	ft_printf_fd(STDERR_FILENO, " Exiting...\n");
	return (1);
}

t_data		init_data(char *file)
{
	int			fd;
	t_data		data;

	if ((fd = open(file, O_RDONLY)) == -1)
		exit(param_error());
	data.x = 0;
	data.y = 0;
	data.zmax = 0;
	data.mod = 1;
	data.zoom = 100;
	data.map = NULL;
	data.iso = NULL;
	data.xrot = 2;
	data.yrot = 1.5;
	data = get_nb_line(fd, data);
	close(fd);
	return (data);
}

int			main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (param_error());
	if (!ft_strstr(av[1], ".fdf"))
		return (param_error());
	ft_printf("Starting\n");
	data = init_data(av[1]);
	ft_printf("init_data DONE\n");
	data = init_map(av[1], data);
	ft_printf("init_map DONE\n");
	data.map = shift_point(data, data.map);
	ft_printf("shift_point DONE\n");
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 1000, 1000, "fdf");
	data.iso = iso_pro(&data, data.map);
	launch_render(data.iso, &data);
	return (0);
}
