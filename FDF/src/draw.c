/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:58:15 by jbuys             #+#    #+#             */
/*   Updated: 2016/11/04 13:40:37 by jbuys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static int			draw_line(t_env *e, int clr, float *v1, float *v2)
{
	t_dw_line		p2;

	p2.slope = (v2[1] - v1[1]) / (v2[0] - v1[0]);
	p2.x = v1[0];
	p2.y = v1[1];
	while (p2.x < v2[0])
	{
		mlx_pixel_put(e->mlx.mlx, e->mlx.win, p2.x, p2.y, clr);
		p2.x += 1;
		p2.y += p2.slope;
	}
	p2.x = v1[0];
	p2.y = v1[1];
	p2.slope = (v2[0] - v1[0]) / (v2[1] - v1[1]);
	while (p2.y < v2[1])
	{
		mlx_pixel_put(e->mlx.mlx, e->mlx.win, p2.x, p2.y, clr);
		p2.y += 1;
		p2.x += p2.slope;
	}
	return (0);
}

static int			draw_line_v(t_env *e, float *v, float x2, float y2)
{
	t_dw_line p2;
	p2.slope = (y2 - v[1]) / (x2 - v[0]);
	p2.x = v[0];
	p2.y = v[1];
	while (p2.x < x2)
	{
		mlx_pixel_put(e->mlx.mlx, e->mlx.win, p2.x, p2.y, 0xFFFFFF);
		p2.x += 1;
		p2.y += p2.slope;
	}
	p2.x = v[0];
	p2.y = v[1];
	p2.slope = (x2 - v[0]) / (y2 - v[1]);
	while (p2.y < y2)
	{
		mlx_pixel_put(e->mlx.mlx, e->mlx.win, p2.x, p2.y, 0xFFFFFF);
		p2.y += 1;
		p2.x += p2.slope;
	}
	return (0);
}

static void			draw_square(t_env *env, t_dw_grid p1, int s)
{
	t_dw_sq		c;

	c.z = p1.hgt;
	c.x = p1.dwx;
	c.y = p1.dwy;
	c.y -= c.z;
	c.c1[0] = c.x;
	c.c1[1] = c.y;
	c.c2[0] = c.x + s;
	c.c2[1] = c.y - (s / 2);
	c.c3[0] = c.x + (s * 2);
	c.c3[1] = c.y;
	c.c4[0] = c.x + s;
	c.c4[1] = c.y + (s / 2);
	draw_line(env, p1.clr, c.c1, c.c2);
	draw_line_v(env, c.c1, c.x, c.y + c.z);
	draw_line(env, p1.clr, c.c2, c.c3);
	draw_line_v(env, c.c2, c.x + s, c.y - (s / 2) + c.z);
	draw_line(env, p1.clr, c.c4, c.c3);
	draw_line_v(env, c.c3, c.x + (s * 2), c.y + c.z);
	draw_line(env, p1.clr, c.c1, c.c4);
	draw_line_v(env, c.c4, c.x + s, c.y + (s / 2) + c.z);
}

static int			get(t_env *env, char **argv)
{
	static char *str = NULL;
	static int	i = 1;
	char		result[3];

 	if (str == NULL)
	{
		str = (char *)malloc(sizeof(char) * BUFFER);
 		init_file(env, str, argv);
	}
	while (str[i++] != '\0')
	{
		if (str[i - 1] >= 48 && str[i - 1] <= 57 &&
		(str[i] == ' ' || str[i] == '\n'))
			return(atoi(&str[i - 1]) * 5);
		if ((str[i - 1] >= 48 && str[i - 1] <= 57) && str[i] >= 48 && str[i] <= 57
		&& (str[i + 1] == ' ' || str[i + 1] == '\n'))
		{
			result[0] = str[i - 1];
			result[1] = str[i];
			i += 2;
			return (atoi(result) * 5);
		}
	}
	free(str);
	return (0);
}

void				draw_grid(t_env *env, char **argv)
{
	t_dw_grid p1;

	p1.strtx = 50;
	p1.strty = 500;
	while (env->y > 0)
	{
		p1.dwy = p1.strty;
		p1.dwx = p1.strtx;
		p1.tmpx = env->x;
		while (p1.tmpx > 0)
		{
			p1.clr = 0x80FFFFFF;
			p1.hgt = get(env, argv);
			if (p1.hgt != 0)
				p1.clr = 0xFFFFFF;
			draw_square(env, p1, env->size);
			p1.tmpx -= 1;
			p1.dwx += env->size;
			p1.dwy -= env->size / 2;
		}
		p1.strtx += env->size;
		p1.strty += env->size / 2;
		env->y--;
	}
}
