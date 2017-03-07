/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 12:06:15 by aguellil          #+#    #+#             */
/*   Updated: 2017/03/05 13:04:22 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <domino.h>

t_player *ft_player_create(int id)
{
	t_player	*aplayer;

	if (!(aplayer = (t_player *)malloc(sizeof(t_player))))
		return (0);
	aplayer->id = id;
	aplayer->score = 0;
	aplayer->dominoes = 0;
	return (aplayer);
}
