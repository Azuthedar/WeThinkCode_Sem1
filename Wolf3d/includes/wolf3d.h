/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 15:17:58 by jbuys             #+#    #+#             */
/*   Updated: 2016/06/24 11:03:11 by jbuys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/time.h>
# include "../libft/libft.h"
# include <stdio.h>
# include <errno.h>

# define WIN_W	800
# define WIN_H	800
# define RED 0xFF0000

# define ESCAPE 53
# define FORWARD 13
# define BACKWARD 1
# define LEFT 0
# define RIGHT 2

# define TEXTWALL 1

typedef struct		s_img
{
	void			*i;
	char			*d;
	int				bpp;
	int				sz;
	int				env;
}					t_img;

typedef struct		s_keys
{
	int				forward;
	int				backward;
	int				left;
	int				right;
}					t_keys;

typedef struct		s_player
{
	double			x_pos;
	double			y_pos;
	double			x_dir;
	double			y_dir;
	double			rotspd;
	double			mvspeed;
	double			camerax;
	int				x_step;
	int				y_step;
	int				hit;
	int				side;
	int				sprint;
	t_keys			keypress;
}					t_player;

typedef struct		s_ray
{
	double			x_pos;
	double			y_pos;
	double			x_dir;
	double			y_dir;
	double			x_plane;
	double			y_plane;
	double			x_side_dist;
	double			y_side_dist;
	double			x_delta_dist;
	double			y_delta_dist;
	int				x_pos_map;
	int				y_pos_map;
	int				line_height;
	int				draw_start;
	int				draw_end;
}					t_ray;

typedef struct		s_map
{
	int				**map;
	int				display;
	int				x_size;
	int				y_size;
}					t_map;

typedef struct		s_env
{
	double			*mlx;
	double			*win;
	t_img			i;
	t_player		player;
	t_map			map;
	t_ray			r;
	double			perp_wall_dist;
	double			time;
	double			oldtime;
	long int		frametime;
}					t_env;

typedef struct		s_rgb
{
	int				r;
	int				g;
	int				b;
}					t_rgb;

typedef struct		s_coordint
{
	int				x;
	int				y;
}					t_coordint;

void				check_file(t_env *te, char **argv);
void				draw_line(int x, t_env *te, t_rgb *color);
void				color(t_env *te, t_rgb *color);
void				framecount(t_env *te);
void				moving(t_env *te);
int					keypress(int keypress, t_env *te);
int					keyrelease(int keyrelease, t_env *te);
int					loop_hook(t_env *te);
int					quit(void);
int					frequency(t_env *te);

#endif
