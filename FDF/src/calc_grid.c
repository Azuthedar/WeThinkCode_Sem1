/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 13:26:35 by jbuys             #+#    #+#             */
/*   Updated: 2016/11/03 13:26:38 by jbuys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void		calc_grid(t_env *e)
{
	int			i;
	int			j;

	i = 0;
	e->gc.s = (char *)malloc(BUFFER);
	read(e->fd, (void *)e->gc.s, BUFFER);
	while (e->gc.s[i] != '\0')
	{
		j = 0;
		init_buff(e, i);
		while (e->gc.s[i] == ' ')
		{
			j++;
			spaces_check(j);
			i++;
		}
		if (e->gc.s[i] == '\n')
			e->y++;
		i++;
	}
	free(e->gc.s);
	e->x++;
}
