/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_possible_moves_vertical.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegroux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 16:22:31 by tlegroux          #+#    #+#             */
/*   Updated: 2017/03/05 22:40:31 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domino.h"

static void	child_change(t_domino *child, int x, int y)
{
	child->x = x;
	child->y = y;
}

t_list		*list_vertical_moves(t_extremity *extremity, t_domino *child)
{
	t_list	*list;

	list = NULL;
	child->orientation = HORIZONTAL;
	child->direction = RIGHT;
	child_change(child, -1, 0);
	ft_lstadd(&list, ft_lstnew(make_move(extremity, child), sizeof(t_move)));
	child_change(child, 0, -1);
	ft_lstadd(&list, ft_lstnew(make_move(extremity, child), sizeof(t_move)));
	child_change(child, child->x, +1);
	ft_lstadd(&list, ft_lstnew(make_move(extremity, child), sizeof(t_move)));
	child->direction = LEFT;
	ft_lstadd(&list, ft_lstnew(make_move(extremity, child), sizeof(t_move)));
	child_change(child, child->x, -1);
	ft_lstadd(&list, ft_lstnew(make_move(extremity, child), sizeof(t_move)));
	child_change(child, +1, 0);
	ft_lstadd(&list, ft_lstnew(make_move(extremity, child), sizeof(t_move)));
	child->orientation = VERTICAL;
	child->orientation = DOWN;
	child_change(child, 0, -1);
	ft_lstadd(&list, ft_lstnew(make_move(extremity, child), sizeof(t_move)));
	child->orientation = UP;
	child_change(child, 0, +1);
	ft_lstadd(&list, ft_lstnew(make_move(extremity, child), sizeof(t_move)));
	return (list);
}

t_list		*list_vertical_moves_flipped(t_extremity *extrem, t_domino *child)
{
	t_list	*list;

	list = NULL;
	child->orientation = HORIZONTAL;
	child->direction = LEFT;
	child_change(child, -2, 0);
	ft_lstadd(&list, ft_lstnew(make_move(extrem, child), sizeof(t_move)));
	child_change(child, 0, -2);
	ft_lstadd(&list, ft_lstnew(make_move(extrem, child), sizeof(t_move)));
	child_change(child, child->x, +2);
	ft_lstadd(&list, ft_lstnew(make_move(extrem, child), sizeof(t_move)));
	child->direction = RIGHT;
	ft_lstadd(&list, ft_lstnew(make_move(extrem, child), sizeof(t_move)));
	child_change(child, child->x, -2);
	ft_lstadd(&list, ft_lstnew(make_move(extrem, child), sizeof(t_move)));
	child_change(child, +2, 0);
	ft_lstadd(&list, ft_lstnew(make_move(extrem, child), sizeof(t_move)));
	child->orientation = VERTICAL;
	child->orientation = UP;
	child_change(child, 0, -2);
	ft_lstadd(&list, ft_lstnew(make_move(extrem, child), sizeof(t_move)));
	child->orientation = DOWN;
	child_change(child, 0, +2);
	ft_lstadd(&list, ft_lstnew(make_move(extrem, child), sizeof(t_move)));
	return (list);
}
