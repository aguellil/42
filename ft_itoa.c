/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 18:23:54 by aguellil          #+#    #+#             */
/*   Updated: 2016/01/28 00:42:44 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
** 1. Implementation
*/

/*
** 1.1 Iterative
*/

static int	ft_nb_of_digits(int n)
{
	int	nb_of_digits;

	if (n < 0)
		n = -n;
	nb_of_digits = 1;
	while (n / 10 != 0)
	{
		nb_of_digits++;
		n = n / 10;
	}
	return (nb_of_digits);
}

char		*ft_itoa(int n)
{
	unsigned int	abs_n;
	char			*s;
	int				size_s;
	int				i;

	abs_n = n * ((n > 0) - (n < 0));
	size_s = (n < 0) + ft_nb_of_digits(n) + 1;
	s = (char *)malloc(size_s * sizeof(char));
	if (!s)
		return (0);
	i = size_s - 1;
	s[i] = '\0';
	i--;
	while (i >= (n < 0))
	{
		s[i] = '0' + abs_n % 10;
		abs_n = abs_n / 10;
		i--;
	}
	if (n < 0)
		s[0] = '-';
	return (s);
}
