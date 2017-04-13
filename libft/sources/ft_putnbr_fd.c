/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguellil <yguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:46:57 by yguellil          #+#    #+#             */
/*   Updated: 2016/12/09 10:18:36 by yguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		sign;

	sign = 1;
	if (n < 0)
		sign = -1;
	if ((n / 10) != 0)
		ft_putnbr_fd((n / 10), fd);
	else if (n < 0)
		ft_putchar_fd('-', fd);
	ft_putchar_fd(((n % 10) * sign + '0'), fd);
	return ;
}
