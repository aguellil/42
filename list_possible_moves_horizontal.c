/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_possible_moves_horizontal.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegroux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 16:21:28 by tlegroux          #+#    #+#             */
/*   Updated: 2017/03/05 22:39:35 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domino.h"

static void	child_change(t_domino *child, int x, int y)
{
	child->x = x;
	child->y = y;
}

t_list		*list_horizontal_moves(t_extremity *extremity, t_domino *child)
{
	t_list	*list;

	list = NULL;
	child->orientation = VERTICAL;
	child->direction = DOWN;
	child_change(child, 0, -1);
	ft_lstadd(&list, ft_lstnew(make_move(extremity, child), sizeof(t_move)));
	child_change(child, -1, 0);
	ft_lstadd(&list, ft_lstnew(make_move(extremity, child), sizeof(t_move)));
	child_change(child, 1, child->y);
	ft_lstadd(&list, ft_lstnew(make_move(extremity, child), sizeof(t_move)));
	child->direction = UP;
	ft_lstadd(&list, ft_lstnew(make_move(extremity, child), sizeof(t_move)));
	child_change(child, -1, child->y);
	ft_lstadd(&list, ft_lstnew(make_move(extremity, child), sizeof(t_move)));
	child_change(child, 0, +1);
	ft_lstadd(&list, ft_lstnew(make_move(extremity, child), sizeof(t_move)));
	child->orientation = HORIZONTAL;
	child->orientation = LEFT;
	child_change(child, -1, 0);
	ft_lstadd(&list, ft_lstnew(make_move(extremity, child), sizeof(t_move)));
	child->orientation = RIGHT;
	child_change(child, +1, 0);
	ft_lstadd(&list, ft_lstnew(make_move(extremity, child), sizeof(t_move)));
	return (list);
}

t_list		*list_horizontal_moves_flipped(t_extremity *extrem, t_domino *child)
{
	t_list	*list;

	list = NULL;
	child->orientation = VERTICAL;
	child->direction = UP;
	child_change(child, 0, -2);
	ft_lstadd(&list, ft_lstnew(make_move(extrem, child), sizeof(t_move)));
	child_change(child, -2, 0);
	ft_lstadd(&list, ft_lstnew(make_move(extrem, child), sizeof(t_move)));
	child_change(child, +2, child->y);
	ft_lstadd(&list, ft_lstnew(make_move(extrem, child), sizeof(t_move)));
	child->direction = DOWN;
	ft_lstadd(&list, ft_lstnew(make_move(extrem, child), sizeof(t_move)));
	child_change(child, -2, child->y);
	ft_lstadd(&list, ft_lstnew(make_move(extrem, child), sizeof(t_move)));
	child_change(child, 0, +2);
	ft_lstadd(&list, ft_lstnew(make_move(extrem, child), sizeof(t_move)));
	child->orientation = HORIZONTAL;
	child->orientation = RIGHT;
	child_change(child, -2, 0);
	ft_lstadd(&list, ft_lstnew(make_move(extrem, child), sizeof(t_move)));
	child->orientation = LEFT;
	child_change(child, +2, 0);
	ft_lstadd(&list, ft_lstnew(make_move(extrem, child), sizeof(t_move)));
	return (list);
}
