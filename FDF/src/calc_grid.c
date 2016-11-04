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
	e->gc.s = (char *)malloc(sizeof(BUFFER));
	read(e->fd, (void *)e->gc.s, BUFFER);
	while (e->gc.s[i] != '\0')
	{
		j = 0;
		if (e->gc.s[i] == ' ' && e->gc.s[i + 1] == ' ' && e->y == 0)
			e->x++;
		if (e->gc.s[i] == ' ' && e->gc.s[i + 1] >= 48 && e->gc.s[i + 1] <= 57
			&& e->gc.s[i + 2] >= 48 && e->gc.s[i + 2] <= 57 && e->y == 0)
			e->x++;
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