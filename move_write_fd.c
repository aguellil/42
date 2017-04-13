/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_write_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 17:36:55 by aguellil          #+#    #+#             */
/*   Updated: 2017/03/05 18:07:17 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domino.h"

void	move_write_fd(t_move *move, int fd)
{
	ft_putstr_fd("Player: ", fd);
	ft_putnbr_fd((int)(move->player), fd);
	ft_putstr_fd("\nAction: ", fd);
	ft_putnbr_fd((int)(move->action), fd);
	ft_putstr_fd("\nDomino: ", fd);
	ft_putnbr_fd((int)(move->action), fd);
	ft_putstr_fd("\nParent:\n", fd);
	extremity_write_fd(move->parent, fd);
}
