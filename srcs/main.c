/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 13:31:51 by hlely             #+#    #+#             */
/*   Updated: 2018/04/25 10:34:17 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_tab(t_point **tab)
{
	int		i;
	int		j;

	i = 0;
	while (tab && tab[i])
	{
		j = 0;
		ft_printf("[");
		while (j < tab[i][j].x_max)
		{
			ft_printf("%4d,%4d,%4d|",
					(int)tab[i][j].x, (int)tab[i][j].y, (int)tab[i][j].z);
			j++;
		}
		ft_printf("]\n");
		i++;
	}
}

t_point	cpy_point(t_point point)
{
	t_point	cpy;

	cpy.x = point.x;
	cpy.y = point.y;
	cpy.z = point.z;
	cpy.x_max = point.x_max;
	cpy.y_max = point.y_max;
	cpy.native = point.native;
	return (cpy);
}

t_point	**cpy_map(t_point **point)
{
	int		i;
	int		j;
	t_point	**cpy;

	i = 0;
	if (!(cpy = ft_memalloc(sizeof(t_point*) * (point[0][0].y_max + 1))))
		return (NULL);
	while (point && point[i])
	{
		if (!(cpy[i] = ft_memalloc(sizeof(t_point) * (point[0][0].x_max + 1))))
			return (NULL);
		j = 0;
		while (j < point[i][j].x_max)
		{
			cpy[i][j] = cpy_point(point[i][j]);
			j++;
		}
		i++;
	}
	return (cpy);
}

int		main(int ac, char **av)
{
	t_point			**tab;
	t_data			data;

	if (ac != 2)
		return (1);
	data.modif = 0.1;
	tab = parse_input(av[1]);
	data.tab = tab;
	data.saved = (const t_point**)cpy_map(tab);
	printf("FIRST:%d\n", (int)data.saved[0][0].x);
	tab = iso_pro(tab, &data);
	data.dx = data.xmax - data.xmin;
	data.dy = data.ymax - data.ymin;
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 1000, 1000, "fdf");
	launch_render(tab, &data);
	return (0);
}
