/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 12:28:13 by jbuys             #+#    #+#             */
/*   Updated: 2016/05/25 12:28:14 by jbuys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	char		*tmp;
	const char	*tmp2;
	size_t		i;

	i = 0;
	tmp = (char*)s1;
	tmp2 = (char*)s2;
	while (i < n)
	{
		tmp[i] = tmp2[i];
		i++;
	}
	return (s1);
}
