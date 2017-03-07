/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 12:26:08 by aguellil          #+#    #+#             */
/*   Updated: 2017/03/05 12:28:41 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domino.h"

void	ft_player_free(t_player *aplayer)
{
	if (aplayer == 0)
		return ;
	ft_domino_free(aplayer->domino);
	free (aplayer);
	return ;
}
