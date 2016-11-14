/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdebruyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 14:11:46 by cdebruyn          #+#    #+#             */
/*   Updated: 2016/06/24 11:05:08 by jbuys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/wolf3d.h"

int			quit(void)
{
	exit(0);
}

int			keypress(int keypress, t_env *te)
{
	if (keypress == FORWARD)
		te->player.keypress.forward = 1;
	if (keypress == BACKWARD)
		te->player.keypress.backward = 1;
	if (keypress == LEFT)
		te->player.keypress.left = 1;
	if (keypress == RIGHT)
		te->player.keypress.right = 1;
	return (0);
}

int			keyrelease(int keyrelease, t_env *te)
{
	if (keyrelease == ESCAPE)
		exit(0);
	if (keyrelease == FORWARD)
		te->player.keypress.forward = 0;
	if (keyrelease == BACKWARD)
		te->player.keypress.backward = 0;
	if (keyrelease == LEFT)
		te->player.keypress.left = 0;
	if (keyrelease == RIGHT)
		te->player.keypress.right = 0;
	return (0);
}

static void	turn(t_env *te, char determ)
{
	double		old_dir;
	double		prev_plane;
	int			pos_neg;

	old_dir = te->player.x_dir;
	pos_neg = 1;
	prev_plane = te->r.x_plane;
	if (determ == 'R')
		pos_neg = -1;
	te->player.x_dir = te->player.x_dir * cos(pos_neg * te->player.rotspd)
		- te->player.y_dir * sin(pos_neg * te->player.rotspd);
	te->player.y_dir = old_dir * sin(pos_neg * te->player.rotspd)
		+ te->player.y_dir * cos(pos_neg * te->player.rotspd);
	te->r.x_plane = te->r.x_plane * cos(pos_neg * te->player.rotspd)
		- te->r.y_plane * sin(pos_neg * te->player.rotspd);
	te->r.y_plane = prev_plane * sin(pos_neg * te->player.rotspd)
		+ te->r.y_plane * cos(pos_neg * te->player.rotspd);
}

void		moving(t_env *te)
{
	if (te->player.keypress.forward)
	{
		if (!(te->map.map[(int)(te->player.x_pos + te->player.x_dir
			* te->player.mvspeed)][(int)te->player.y_pos]))
			te->player.x_pos += te->player.x_dir * te->player.mvspeed;
		if (!(te->map.map[(int)(te->player.x_pos)][(int)(te->player.y_pos
			+ te->player.y_dir * te->player.mvspeed)]))
			te->player.y_pos += te->player.y_dir * te->player.mvspeed;
	}
	if (te->player.keypress.backward)
	{
		if (!(te->map.map[(int)(te->player.x_pos - te->player.x_dir
			* te->player.mvspeed)][(int)te->player.y_pos]))
			te->player.x_pos -= te->player.x_dir * te->player.mvspeed;
		if (!(te->map.map[(int)(te->player.x_pos)][(int)(te->player.y_pos
			- te->player.y_dir * te->player.mvspeed)]))
			te->player.y_pos -= te->player.y_dir * te->player.mvspeed;
	}
	if (te->player.keypress.right)
		turn(te, 'R');
	if (te->player.keypress.left)
		turn(te, 'L');
}
