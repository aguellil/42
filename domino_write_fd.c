/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   domino_write_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 16:35:28 by aguellil          #+#    #+#             */
/*   Updated: 2017/03/05 17:33:50 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domino.h"

void	domino_write_fd(t_domino *domino, int fd)
{
	ft_putstr_fd("n1:", fd);
	ft_putchar_fd('0' + domino->n1, fd);
	ft_putstr_fd(" n2:", fd);
	ft_putchar_fd('0' + domino->n2, fd);
	ft_putstr_fd(" o:", fd);
	ft_putchar_fd('0' + domino->orientation, fd);
	ft_putstr_fd(" d:", fd);
	ft_putchar_fd('0' + domino->direction, fd);
	ft_putstr_fd(" x:", fd);
	ft_putnbr_fd(domino->x, fd);
	ft_putstr_fd(" y:", fd);
	ft_putnbr_fd(domino->y, fd);
	return ;
}
