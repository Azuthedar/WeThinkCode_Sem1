/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 12:34:42 by jbuys             #+#    #+#             */
/*   Updated: 2016/05/25 12:34:43 by jbuys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	int	i;

	i = 0;
	while (s2[i] != '\0' && n > 0)
	{
		s1[i] = s2[i];
		i++;
		n--;
	}
	if (n > 0)
	{
		while (n > 0)
		{
			s1[i] = '\0';
			i++;
			n--;
		}
	}
	return (s1);
}
