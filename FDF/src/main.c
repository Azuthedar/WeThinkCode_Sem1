/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 09:49:48 by jbuys             #+#    #+#             */
/*   Updated: 2016/11/03 09:49:50 by jbuys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int			main(int argc, char **argv)
{
	t_env		*e;

	if (argc == 2)
	{
		e = (t_env *)malloc(sizeof(t_env));
		init_func(e, argv);
		mlx_loop(e->mlx.mlx);
		close(e->fd);
		free(&e);
	}
	else
		ft_putendl("Invalid Arguments");
	return (0);
}
