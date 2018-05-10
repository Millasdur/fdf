/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 11:20:13 by hlely             #+#    #+#             */
/*   Updated: 2018/05/10 16:49:41 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		*fill_point(char *line, int y, t_point *point)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] != ' ')
		{
			point[j].x = j;
			point[j].y = y;
			point[j].z = ft_atoi(line + i);
			while (line[i] && line[i] != ' ')
				i++;
			j++;
		}
		if (line[i] == ' ')
			while (line[i] && line[i] == ' ')
				i++;
	}
	return (point);
}

t_data		fill_map(char *file, t_data data)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	line = NULL;
	if ((fd = open(file, O_RDONLY)) == -1)
		exit(EXIT_FAILURE);
	while (get_next_line(fd, &line))
	{
		if (!(data.map[i] = ft_memalloc(sizeof(t_point) * (data.x + 1))))
			exit(EXIT_FAILURE);
		data.map[i] = fill_point(line, i, data.map[i]);
		ft_strdel(&line);
		i++;
	}
	ft_strdel(&line);
	close(fd);
	return (data);
}
