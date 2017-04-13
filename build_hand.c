/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_hand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegroux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 21:10:40 by tlegroux          #+#    #+#             */
/*   Updated: 2017/03/05 22:00:09 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domino.h"

void	build_opponent_hand(t_gamestate *gamestate)
{
	t_domino	*domino;
	int			i;
	int			j;

	i = 0;
	while (i <= 6)
	{
		j = i;
		while (j <= 6)
		{
			if (!(domino = malloc(sizeof(t_domino))))
				exit(1);
			domino->n1 = i;
			domino->n2 = j;
			ft_lstadd(&(gamestate->opponent->hand),
					ft_lstnew(domino, sizeof(t_domino)));
			j++;
		}
		i++;
	}
}
