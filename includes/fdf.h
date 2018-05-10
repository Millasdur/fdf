/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 13:28:38 by hlely             #+#    #+#             */
/*   Updated: 2018/05/10 15:41:52 by hlely            ###   ########.fr       */
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

typedef struct		s_point
{
	double			x;
	double			y;
	double			z;
}					t_point;

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

typedef struct		s_data
{
	int				x;
	int				y;
	double			mod;
	t_point			**map;
	t_point			**iso;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
}					t_data;

t_data				init_map(char *file, t_data data);
t_data				get_nb_line(int fd, t_data data);
t_data				fill_map(char *file, t_data data);

t_point				**iso_pro(t_data data, t_point **point);

unsigned int		*ft_put_pixel(int x, int y, unsigned int *img, t_data data);
unsigned int		*draw_seg_right(t_draw draw, unsigned int *img,
				t_point **map, t_data);
unsigned int		*draw_seg_down(t_draw draw, unsigned int *img,
				t_point **map, t_data);

void				launch_render(t_point **map, t_data *data);

#endif
