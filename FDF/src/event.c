/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 11:03:59 by jbuys             #+#    #+#             */
/*   Updated: 2016/11/03 11:04:12 by jbuys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int		event(int keycode, t_env *env)
{
	if (keycode == 53)
	{
		mlx_destroy_window(env->mlx.mlx, env->mlx.win);
		exit(0);
	}
	return (0);
}

int		quit(t_env *env)
{
	mlx_destroy_window(env->mlx.mlx, env->mlx.win);
	exit(0);
	return (0);
}