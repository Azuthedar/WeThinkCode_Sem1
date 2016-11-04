/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 09:53:40 by jbuys             #+#    #+#             */
/*   Updated: 2016/11/03 09:53:42 by jbuys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/includes/libft.h"

# define H 800
# define W 800
# define BUFFER 10485760

typedef struct			s_mlx
{
	void				*mlx;
	void				*win;

}						t_mlx;

typedef struct			s_dw_grid
{
	int					tmpx;
	int					strtx;
	int					strty;
	int					dwx;
	int					dwy;
	int					hgt;
	int					clr;
}						t_dw_grid;

typedef struct			s_dw_line
{
	float				slope;
	float				x;
	float				y;
}						t_dw_line;

typedef struct			s_calc_grid
{
	int					i;
	int					x1;
	int					y2;
	char				*s;
}						t_calc_grid;

typedef struct			s_dw_sq
{
	int					y;
	int					x;
	int					z;
	float				c1[2];
	float				c2[2];
	float				c3[2];
	float				c4[2];
	float				v1[2];
	float				v2[2];
	float				v3[2];
	float				v4[2];
}						t_dw_sq;

typedef struct			s_env
{
	t_mlx				mlx;
	t_dw_grid			dwg;
	t_dw_line			dwl;
	t_calc_grid			gc;
	t_dw_sq				dwsq;
	int					fd;
	int					lines;
	int					x;
	int					y;
	int					size;
	void				*a[2];
}						t_env;

void					init_func(t_env *env, char **argv);
void					init_all(t_env *env, char **argv);
void					init_file(t_env *env, char *str, char **argv);
void					draw_win(t_env *env);
void					calc_grid(t_env *e);
void					draw_grid(t_env *env, char **argv);

int						event(int keycode, t_env *env);
int						quit(t_env *env);
int						check_size(t_env *env);

void					error_check(t_env *env);
void					spaces_check(int j);

#endif
