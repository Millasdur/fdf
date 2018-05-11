/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 13:28:38 by hlely             #+#    #+#             */
/*   Updated: 2018/05/11 11:45:32 by hlely            ###   ########.fr       */
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

# define EXIT 53
# define INC 69
# define DEC 78
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define M 46
# define L 37

typedef struct		s_point
{
	double			x;
	double			y;
	double			z;
}					t_point;

typedef struct		s_draw
{
	int		i;
	int		j;
	int		x;
	int		y;
	int		xi;
	int		yi;
	int		xf;
	int		yf;
	int		dx;
	int		dy;
	int		x_inc;
	int		y_inc;
	int		sum;
}					t_draw;

typedef struct		s_data
{
	int				x;
	int				y;
	double			xmin;
	double			xmax;
	double			ymin;
	double			ymax;
	double			zmax;
	double			mod;
	double			zoom;
	double			xrot;
	double			yrot;
	t_point			**map;
	t_point			**iso;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
}					t_data;

t_data				init_map(char *file, t_data data);
t_data				get_nb_line(int fd, t_data data);
t_data				fill_map(char *file, t_data data);

t_point				**iso_pro(t_data *data, t_point **point);
t_point				**shift_point(t_data data, t_point **map);
t_point				**shift_iso(t_data data, t_point **map);

unsigned int		*ft_put_pixel(t_draw draw, unsigned int *img,
						t_data data, t_point point);
unsigned int		*draw_seg_right(t_draw draw, unsigned int *img,
						t_point **map, t_data data);
unsigned int		*draw_seg_down(t_draw draw, unsigned int *img,
						t_point **map, t_data data);

void				launch_render(t_point **map, t_data *data);
void				move_x(t_data *data, int x);
void				shift_x(t_data *data, int x);
void				move_y(t_data *data, int x);
void				shift_y(t_data *data, int x);
void				zoom(t_data *data, int z);
void				zoom_in_out(t_data *data, int z);
void				rotxy(t_data *data, double z);

int					key_event(int key, t_data *data);
int					clean_map(t_data data, t_point ***point);
#endif
