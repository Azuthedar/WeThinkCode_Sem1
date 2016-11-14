/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 12:35:30 by jbuys             #+#    #+#             */
/*   Updated: 2016/05/25 12:35:30 by jbuys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*fct;

	fct = NULL;
	while (*s)
	{
		if (*s == (char)c)
			fct = (char *)s;
		s++;
	}
	if (*s == (char)c)
		fct = (char *)s;
	return (fct);
}
