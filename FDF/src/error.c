/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:58:08 by jbuys             #+#    #+#             */
/*   Updated: 2016/11/04 12:58:09 by jbuys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	error_check(t_env *env)
{
	if (env->fd < 0)
	{
		ft_putendl("Invalid file");
		exit(0);
	}
}

void	spaces_check(int j)
{
	if (j > 2)
	{
		ft_putendl("Invalid Format");
		exit(0);
	}
}