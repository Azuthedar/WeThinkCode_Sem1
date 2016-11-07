/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 10:07:05 by jbuys             #+#    #+#             */
/*   Updated: 2016/07/28 10:24:13 by jbuys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int		ft_isspace(char c)
{
	if (c == ' ' ||
			c == '\n' ||
			c == '\t' ||
			c == '\v' ||
			c == '\f' ||
			c == '\r')
	{
		return (1);
	}
	return (0);
}

int				ft_atoi(const char *str)
{
	int		i;
	int		sign;
	int		nb;

	i = 0;
	nb = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		nb = nb * 10 + (str[i] - '0') * sign;
		i++;
	}
	return (nb);
}