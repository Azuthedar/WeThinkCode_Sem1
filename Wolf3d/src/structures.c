/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 15:26:16 by jbuys             #+#    #+#             */
/*   Updated: 2016/06/20 14:45:27 by jbuys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		structures(t_coord *tc, t_mlx *tm)
{
	if (tc->side == 0 && hit_wall(tc))
	{
		tc->perp_wall_dist = ((tc->x_map - tc->x_ray_pos + (1 - tc->x_step) / 2)
				/ tc->x_ray_dir);
	}
	else
	{
		hit_wall(tc);
		tc->perp_wall_dist = ((tc->y_map - tc->y_ray_pos + (1 - tc->y_step) / 2)
				/ tc->y_ray_dir);
	}
	tc->line_height = (int)(WIN_H / tc->perp_wall_dist);
	tc->line_width = tc->line_height / 2;
	if (tc->draw_start < 0)
		tc->draw_start = (-1 * tc->line_height / 2) + (WIN_H / 2);
	tc->draw_end = (tc->line_height / 2) + (H / 2);
	if (tc->draw_end >= WIN_H)
		tc->draw_end = WIN_H - 1;
	return (0);
}
