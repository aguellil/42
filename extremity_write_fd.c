/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extremity_write_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 17:29:54 by aguellil          #+#    #+#             */
/*   Updated: 2017/03/05 18:07:00 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domino.h"

void	extremity_write_fd(t_extremity *extremity, int fd)
{
	if (extremity == 0)
		return ;
	ft_putstr_fd("x: ", fd);
	ft_putnbr_fd(extremity->x, fd);
	ft_putstr_fd("\ny: ", fd);
	ft_putnbr_fd(extremity->y, fd);
	ft_putstr_fd("\nvalue: ", fd);
	ft_putnbr_fd(extremity->value, fd);
	ft_putstr_fd("\ndomino: ", fd);
	domino_write_fd(extremity->domino, fd);
	return ;
}
