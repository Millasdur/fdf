/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 13:28:38 by hlely             #+#    #+#             */
/*   Updated: 2018/04/24 11:42:25 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>

typedef struct	s_point
{
	double	x;
	double	y;
	double	z;
	double	modif;
	int		x_max;
	int		y_max;
	int		native;
}				t_point;

typedef struct	s_draw
{
	int		i;
	int		j;
	int		xi;
	int		yi;
	int		xf;
	int		yf;
	int		dx;
	int		dy;
	int		x_inc;
	int		y_inc;
	int		sum;
}				t_draw;

int		key_event(int key, void *param);

t_point	**parse_input(char *file);
t_point	**fill_point(t_point **tab, int fd, int y_max);

t_point	**iso_pro(t_point **tab);
t_point	**shift_tab(t_point **tab);

void	launch_render(t_point **tab);

#endif
