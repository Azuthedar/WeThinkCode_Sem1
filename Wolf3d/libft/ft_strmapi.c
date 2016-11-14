/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 12:34:09 by jbuys             #+#    #+#             */
/*   Updated: 2016/05/25 12:34:10 by jbuys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ptr;
	unsigned int	i;

    i = 0;
	ptr = ft_strdup(s);
	while (ptr[i] != 0)
	{
		ptr[i] = f(i, ptr[i]);
		i++;
	}
	return (ptr);
}
