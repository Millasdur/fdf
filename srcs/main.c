/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 13:31:51 by hlely             #+#    #+#             */
/*   Updated: 2018/04/23 18:13:50 by hlely            ###   ########.fr       */
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

	if (ac != 2)
		return (1);
	tab = parse_input(av[1]);
	print_tab(tab);
	ft_printf("----ISO-----\n");
	tab = iso_pro(tab);
	print_tab(tab);
	ft_printf("----SHIFT-----\n");
	tab = shift_tab(tab);
	print_tab(tab);
	launch_render(tab);
	return (0);
}
