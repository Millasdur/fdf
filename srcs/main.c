/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 13:31:51 by hlely             #+#    #+#             */
/*   Updated: 2018/04/24 17:05:15 by hlely            ###   ########.fr       */
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

int		main(int ac, char **av)
{
	t_point			**tab;
	t_data			data;

	if (ac != 2)
		return (1);
	data.modif = 0.1;
	tab = parse_input(av[1]);
	data.tab = tab;
	data.saved = cpy(tab);
	tab = iso_pro(tab, &data);
	data.dx = data.xmax - data.xmin;
	data.dy = data.ymax - data.ymin;
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 1000, 1000, "fdf");
	launch_render(tab, &data);
	return (0);
}
