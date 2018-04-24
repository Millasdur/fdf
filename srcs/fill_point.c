/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 12:55:24 by hlely             #+#    #+#             */
/*   Updated: 2018/04/24 17:08:42 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point	**clean_tmp(char ***tmp)
{
	ft_tabdel(tmp);
	return (0);
}

static int		is_valid(char *tmp)
{
	if (tmp && (ft_isdigit(tmp[0]) ||
				(tmp[0] == '-' && tmp[1] && ft_isdigit(tmp[1])) ||
				(tmp[0] == '+' && tmp[1] && ft_isdigit(tmp[1]))))
		return (1);
	return (0);
}

static t_point	calc_point(int i, int j, int x_max, char *tmp)
{
	t_point point;

	point.x = j;
	point.x_max = x_max;
	point.y = i;
	point.z = ft_atoi(tmp);
	point.native = (point.z == 0) ? 1 : 0;
	return (point);
}

static t_point	**fill_point2(int i, int y_max, char **tmp, t_point **tab)
{
	int		j;

	j = 0;
	while (tmp && tmp[j])
	{
		if (!is_valid(tmp[j]))
			return (clean_tmp(&tmp));
		tab[i][j] = calc_point(i, j, ft_tablen(tmp), tmp[j]);
		tab[i][j].y_max = y_max;
		j++;
	}
	clean_tmp(&tmp);
	return (tab);
}

t_point		**fill_point(t_point **tab, t_point **saved, int fd, int y_max)
{
	int		i;
	char	*line;
	char	**tmp;

	i = 0;
	line = NULL;
	while (get_next_line(fd, &line))
	{
		tmp = ft_strsplit(line, ' ');
		if ((tab[i] = (t_point*)ft_memalloc(sizeof(t_point) *
						(ft_tablen(tmp) + 1))) == NULL)
			return (NULL);
		tab = fill_point2(i, y_max, tmp, tab);
		ft_strdel(&line);
		i++;
	}
	ft_strdel(&line);
	return (tab);
}
