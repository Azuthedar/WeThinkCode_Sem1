/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 10:52:49 by jbuys             #+#    #+#             */
/*   Updated: 2016/06/24 11:36:50 by jbuys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		main(int argc, char **argv)
{
	t_env	te;

	if (argc == 2)
	{
		te.i.i = 0;
		te.time = 0;
		te.oldtime = 0;
		te.player.x_pos = 9;
		te.player.y_pos = 9;
		te.player.x_dir = -1;
		te.player.y_dir = 0;
		te.r.x_plane = 0;
		te.r.y_plane = 0.66;
		te.mlx = mlx_init();
		te.win = mlx_new_window(te.mlx, WIN_W, WIN_H, "Wolf3D");
		check_file(&te, &argv[1]);
		mlx_loop_hook(te.mlx, &loop_hook, &te);
		mlx_hook(te.win, 2, (1L << 1), &keypress, &te);
		mlx_hook(te.win, 3, (1L << 0), &keyrelease, &te);
		mlx_hook(te.win, 17, 0L, &quit, &te);
		mlx_loop(te.mlx);
	}
	return (0);
}
