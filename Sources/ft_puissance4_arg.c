/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puissance4_arg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnguyen <mnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 19:21:05 by mnguyen           #+#    #+#             */
/*   Updated: 2016/02/28 23:14:52 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		ft_puissance4_arg(char **av)
{
	int i;

	if (ft_strlen(av[1]) <= 3 && ft_strlen(av[2]) <= 3)
	{
		i = 0;
		while (av[1][i])
		{
			if (av[1][i] < '0' || av[1][i] > '9')
				return (0);
			i++;
		}
		i = 0;
		while (av[2][i])
		{
			if (av[2][i] < '0' || av[1][i] > '9')
				return (0);
			i++;
		}
		if (ft_atoi(av[1]) >= 6 && ft_atoi(av[2]) >= 7)
			return (1);
	}
	return (0);
}
