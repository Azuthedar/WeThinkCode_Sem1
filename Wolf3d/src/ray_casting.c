/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 15:35:12 by jbuys             #+#    #+#             */
/*   Updated: 2016/06/24 11:01:53 by jbuys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void		ft_ray_casting(t_env *te, int x)
{
	te->player.camerax = 2 * x / (double)WIN_W - 1;
	te->r.x_pos = te->player.x_pos;
	te->r.y_pos = te->player.y_pos;
	te->r.x_dir = te->player.x_dir + (te->r.x_plane * te->player.camerax);
	te->r.y_dir = te->player.y_dir + (te->r.y_plane * te->player.camerax);
	te->r.x_pos_map = (int)te->r.x_pos;
	te->r.y_pos_map = (int)te->r.y_pos;
	te->r.x_delta_dist = sqrt(1 + (te->r.y_dir * te->r.y_dir)
			/ (te->r.x_dir * te->r.x_dir));
	te->r.y_delta_dist = sqrt(1 + (te->r.x_dir * te->r.x_dir)
			/ (te->r.y_dir * te->r.y_dir));
	te->player.hit = 0;
}

static void		ray_direction(t_env *te)
{
	if (te->r.x_dir < 0)
	{
		te->player.x_step = -1;
		te->r.x_side_dist = (te->r.x_pos - te->r.x_pos_map)
			* te->r.x_delta_dist;
	}
	else
	{
		te->player.x_step = 1;
		te->r.x_side_dist = (te->r.x_pos_map + 1.0 - te->r.x_pos)
			* te->r.x_delta_dist;
	}
	if (te->r.y_dir < 0)
	{
		te->player.y_step = -1;
		te->r.y_side_dist = (te->r.y_pos - te->r.y_pos_map)
			* te->r.y_delta_dist;
	}
	else
	{
		te->player.y_step = 1;
		te->r.y_side_dist = (te->r.y_pos_map + 1.0 - te->r.y_pos)
			* te->r.y_delta_dist;
	}
}

static void		digital_differential_analysis(t_env *te)
{
	while (te->player.hit == 0)
	{
		if (te->r.x_side_dist < te->r.y_side_dist)
		{
			te->r.x_side_dist += te->r.x_delta_dist;
			te->r.x_pos_map += te->player.x_step;
			te->player.side = 0;
		}
		else
		{
			te->r.y_side_dist += te->r.y_delta_dist;
			te->r.y_pos_map += te->player.y_step;
			te->player.side = 1;
		}
		if (te->map.map[te->r.x_pos_map][te->r.y_pos_map] > 0)
			te->player.hit = 1;
	}
}

static void		structures(t_env *te)
{
	if (te->player.side == 0)
		te->perp_wall_dist = fabs((te->r.x_pos_map - te->r.x_pos
			+ (1 - te->player.x_step) / 2) / te->r.x_dir);
	else
		te->perp_wall_dist = fabs((te->r.y_pos_map - te->r.y_pos
			+ (1 - te->player.y_step) / 2) / te->r.y_dir);
	te->r.line_height = abs((int)(WIN_H / te->perp_wall_dist));
	te->r.draw_start = (-1 * (te->r.line_height)) / 2 + WIN_H / 2;
	if (te->r.draw_start < 0)
		te->r.draw_start = 0;
	te->r.draw_end = (te->r.line_height / 2) + (WIN_H / 2);
	if (te->r.draw_end >= WIN_H)
		te->r.draw_end = WIN_H - 1;
}

int				loop_hook(t_env *te)
{
	t_rgb	clr;
	int		x;

	if (te->i.i != NULL)
	{
		mlx_destroy_image(te->mlx, te->i.i);
		te->i.i = NULL;
	}
	te->i.i = mlx_new_image(te->mlx, WIN_W, WIN_H);
	x = 0;
	while (x < WIN_W)
	{
		ft_ray_casting(te, x);
		ray_direction(te);
		digital_differential_analysis(te);
		structures(te);
		color(te, &clr);
		draw_line(x, te, &clr);
		x++;
	}
	framecount(te);
	moving(te);
	mlx_put_image_to_window(te->mlx, te->win, te->i.i, 0, 0);
	mlx_string_put(te->mlx, te->win, 20, 20, RED, ft_itoa(frequency(te)));
	return (0);
}
