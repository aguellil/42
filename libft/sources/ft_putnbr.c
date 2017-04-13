/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguellil <yguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:03:51 by yguellil          #+#    #+#             */
/*   Updated: 2016/12/09 10:17:39 by yguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int		sign;

	sign = 1;
	if (n < 0)
		sign = -1;
	if ((n / 10) != 0)
		ft_putnbr(n / 10);
	else if (n < 0)
		ft_putchar('-');
	ft_putchar((n % 10) * sign + '0');
	return ;
}
