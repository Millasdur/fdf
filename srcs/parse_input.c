/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 11:05:31 by hlely             #+#    #+#             */
/*   Updated: 2018/04/23 14:43:16 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_nbline(int fd)
{
	char	*line;
	int		nb_line;

	nb_line = 0;
	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		ft_strdel(&line);
		nb_line++;
	}
	ft_strdel(&line);
	return (nb_line);
}

t_point	**parse_input(char *file)
{
	int		fd;
	int		nb_line;
	t_point	**tab;

	tab = NULL;
	if ((fd = open(file, O_RDONLY)) == -1)
		exit(EXIT_FAILURE);
	nb_line = get_nbline(fd);
	close(fd);
	if ((fd = open(file, O_RDONLY)) == -1)
		exit(EXIT_FAILURE);
	if ((tab = (t_point**)ft_memalloc(sizeof(t_point*) * (nb_line + 1))) == NULL)
		exit(EXIT_FAILURE);
	tab = fill_point(tab, fd, nb_line);
	return (tab);
}
