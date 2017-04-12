/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 20:54:17 by aguellil          #+#    #+#             */
/*   Updated: 2016/01/27 20:59:13 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/*
** 1. Implementation
*/

/*
** 1.1 Iterative
*/

static int	ft_nb_of_digits(int n)
{
	unsigned int	nb_of_digits;

	nb_of_digits = 1;
	while (n / 10 != 0)
	{
		nb_of_digits++;
		n = n / 10;
	}
	return (nb_of_digits);
}

static int	ft_power(int k, size_t n)
{
	int	power;

	power = 1;
	while (n > 0)
	{
		power = power * k;
		n--;
	}
	return (power);
}

void		ft_putnbr_fd(int n, int fd)
{
	char			d;
	unsigned int	nb_of_digits;
	int				sign_n;

	sign_n = (n > 0) - (n < 0);
	if (sign_n == -1)
		write(fd, "-", 1);
	nb_of_digits = ft_nb_of_digits(n);
	while (nb_of_digits > 0)
	{
		d = '0' + sign_n * ((n / ft_power(10, nb_of_digits - 1)) % 10);
		write(fd, &d, 1);
		nb_of_digits--;
	}
	return ;
}

/*
** 1.2 Recursive
*/

/*
**void	ft_putnbr_fd(int n, int fd)
**{
**	char	d;
***
**	d = '0' + ((n > 0) - (n < 0)) * (n % 10);
**	if (n / 10 != 0)
**		ft_putnbr_fd(n / 10, fd);
**	write(fd, &d, 1);
**	return ;
**}
*/
