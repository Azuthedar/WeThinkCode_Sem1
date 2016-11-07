/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_win.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 09:49:41 by jbuys             #+#    #+#             */
/*   Updated: 2016/11/03 09:49:43 by jbuys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void		draw_win(t_env *env)
{
	env->mlx.win = mlx_new_window(env->mlx.mlx, W, H, "FDF");
	if (env->mlx.win == NULL)
	{
		ft_putendl("Error creating window!");
		exit(0);
	}
}
