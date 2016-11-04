/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 10:03:25 by jbuys             #+#    #+#             */
/*   Updated: 2016/11/04 12:58:46 by jbuys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void    init_file(t_env *env, char *str, char **argv)
{
    env->fd = open(argv[1], O_RDONLY);
    read(env->fd, (void*)str, BUFFER);
	if (str[0] <= 48 && str[0] >= 57)
	{
		ft_putendl("File is empty!");
		mlx_destroy_window(env->mlx.mlx, env->mlx.win);
		exit(0);
	}
	if (str == NULL)
	{
		ft_putendl("String is Empty!");
		mlx_destroy_window(env->mlx.mlx, env->mlx.win);
		exit(0);
	}
}

void		init_all(t_env *env, char **argv)
{
	env->mlx.mlx = mlx_init();
	env->x = 0;
	env->y = 0;
	env->gc.x1 = 0;
	env->gc.y2 = 0;
	env->fd = open(argv[1], O_RDONLY);
}

void		init_func(t_env *env, char **argv)
{
	init_all(env, argv);
	error_check(env);
	draw_win(env);
	calc_grid(env);
	env->size = check_size(env);
	draw_grid(env, argv);
	mlx_key_hook(env->mlx.win, event, &env->mlx);
	mlx_hook(env->mlx.win, 17, 0L, quit, &env->mlx);
}

