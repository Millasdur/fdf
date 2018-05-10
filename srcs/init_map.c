/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 09:52:03 by hlely             #+#    #+#             */
/*   Updated: 2018/05/10 21:27:13 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				get_xmax(char *line, int max)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line && line[i])
	{
		if (line[i] != ' ')
		{
			j++;
			while (line[i] && line[i] != ' ')
				i++;
		}
		if (line[i] == ' ')
			while (line[i] && line[i] == ' ')
				i++;
	}
	if (j > max)
		return (j);
	return (max);
}

t_data			get_nb_line(int fd, t_data data)
{
	int		ymax;
	int		xmax;
	char	*line;

	ymax = 0;
	xmax = 0;
	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		xmax = get_xmax(line, xmax);
		ft_strdel(&line);
		ymax++;
	}
	ft_strdel(&line);
	data.x = xmax;
	data.y = ymax;
	return (data);
}

t_data			init_map(char *file, t_data data)
{
	if (!(data.map = malloc(sizeof(t_point*) * (data.y + 1))))
		exit(EXIT_FAILURE);
	data = fill_map(file, data);
	return (data);
}
