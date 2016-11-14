/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/17 13:54:07 by jbuys             #+#    #+#             */
/*   Updated: 2016/06/24 11:01:26 by jbuys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void		set_color(t_rgb *color, int r, int g, int b)
{
	color->r = r;
	color->g = g;
	color->b = b;
}

static void		mlx_image_put_pixel(void *m, t_img *i, t_coordint p, t_rgb *c)
{
	if (i->env)
	{
		i->d[p.y * i->sz + p.x *
			i->bpp / 8] = mlx_get_color_value(m, c->r);
		i->d[p.y * i->sz + p.x *
			i->bpp / 8 + 1] = mlx_get_color_value(m, c->g);
		i->d[p.y * i->sz + p.x *
			i->bpp / 8 + 2] = mlx_get_color_value(m, c->b);
	}
	else
	{
		i->d[p.y * i->sz + i->bpp / 8 * p.x] = mlx_get_color_value(m, c->b);
		i->d[p.y * i->sz + i->bpp / 8 * p.x + 1] = mlx_get_color_value(m, c->g);
		i->d[p.y * i->sz + i->bpp / 8 * p.x + 2] = mlx_get_color_value(m, c->r);
	}
}

void			draw_line(int x, t_env *te, t_rgb *color)
{
	t_coordint	pixel;
	t_rgb		sky_floor;

	pixel.x = x;
	te->i.d = mlx_get_data_addr(te->i.i, &te->i.bpp, &te->i.sz, &te->i.env);
	set_color(&sky_floor, 80, 120, 240);
	pixel.y = 0;
	while (pixel.y < te->r.draw_start)
	{
		mlx_image_put_pixel(te, &te->i, pixel, &sky_floor);
		pixel.y++;
	}
	pixel.y = te->r.draw_start;
	while (pixel.y < te->r.draw_end)
	{
		mlx_image_put_pixel(te, &te->i, pixel, color);
		pixel.y++;
	}
	set_color(&sky_floor, 40, 40, 40);
	pixel.y = te->r.draw_end;
	while (pixel.y < WIN_H)
	{
		mlx_image_put_pixel(te, &te->i, pixel, &sky_floor);
		pixel.y++;
	}
}

void			color(t_env *te, t_rgb *color)
{
	if (te->player.side == 0)
	{
		if (te->player.x_step < 0)
			set_color(color, 0, 190, 190);
		else
			set_color(color, 0, 160, 180);
	}
	else if (te->player.y_step < 0)
		set_color(color, 140, 140, 140);
	else
		set_color(color, 100, 100, 100);
}

void			framecount(t_env *te)
{
	struct timeval	time;

	te->oldtime = te->time;
	gettimeofday(&time, 0);
	te->time = time.tv_sec * 1000 + time.tv_usec / 1000;
	te->frametime = te->time - te->oldtime;
	te->player.mvspeed = te->frametime * 0.003;
	te->player.rotspd = te->frametime * 0.003;
	te->player.sprint = 0.05 * te->player.mvspeed;
}
