/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 13:38:14 by aguellil          #+#    #+#             */
/*   Updated: 2017/04/01 20:24:56 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

void	ai_implement_strategy(t_list *list)
{
	t_row	*row;
	t_row	*next_row;

	row = (t_row *)(list->content);
	if (list->next->content == NULL)
		row->strategy = LEAVE_LAST_MATCHES;
	else
	{
		ai_implement_strategy(list->next);
		next_row = (t_row *)(list->next->content);
		if ((next_row->strategy == LEAVE_LAST_MATCHES && \
			next_row->nb_matches % 4 == 1) || \
			(next_row->strategy == TAKE_LAST_MATCHES && \
			next_row->nb_matches % 4 == 0))
			row->strategy = TAKE_LAST_MATCHES;
		else
			row->strategy = LEAVE_LAST_MATCHES;
	}
	return ;
}

int		ai_determine_matches_to_take(t_list *link)
{
	t_row	*row;
	int		nb_matches_to_take;

	row = (t_row *)(link->content);
	nb_matches_to_take = 0;
	if (row->strategy == LEAVE_LAST_MATCHES)
		nb_matches_to_take = row->nb_matches % 4 == 1 ? \
						1 : \
						row->nb_matches % 4 + \
						4 * (row->nb_matches % 4 == 0) - 1;
	else if (row->strategy == TAKE_LAST_MATCHES)
		nb_matches_to_take = row->nb_matches % 4 == 0 ? \
						1 : \
						row->nb_matches % 4;
	return (nb_matches_to_take);
}
