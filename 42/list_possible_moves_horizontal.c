/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_possible_moves_horizontal.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegroux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 16:21:28 by tlegroux          #+#    #+#             */
/*   Updated: 2017/03/04 18:18:28 by tlegroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domino.h"

t_list	*list_horizontal_moves(t_extremity *extremity, t_domino *child)
{
	t_list	*list;

	list = NULL;
	child->orientation = VERTICAL;
	child->direction = DOWN;
	child->x = 0;
	child->y = -1;
	ft_lstadd(&list, ft_lstnew(make_move(extremity, child), sizeof(t_move)));
	child->x = -1;
	child->y = 0;
	ft_lstadd(&list, ft_lstnew(make_move(extremity, child), sizeof(t_move)));
	child->x = +1;
	ft_lstadd(&list, ft_lstnew(make_move(extremity, child), sizeof(t_move)));
	child->direction = UP;
	ft_lstadd(&list, ft_lstnew(make_move(extremity, child), sizeof(t_move)));
	child->x = -1;
	ft_lstadd(&list, ft_lstnew(make_move(extremity, child), sizeof(t_move)));
	child->x = 0;
	child->y = +1;
	ft_lstadd(&list, ft_lstnew(make_move(extremity, child), sizeof(t_move)));
	child->orientation = HORIZONTAL;
	child->orientation = LEFT;
	child->y = 0;
	child->x = -1;
	ft_lstadd(&list, ft_lstnew(make_move(extremity, child), sizeof(t_move)));
	child->orientation = RIGHT;
	child->y = 0;
	child->x = +1;
	ft_lstadd(&list, ft_lstnew(make_move(extremity, child), sizeof(t_move)));
	return (list);
}

t_list	*list_horizontal_moves_flipped(t_extremity *extremity, t_domino *child)
{
	t_list	*list;

	list = NULL;
	child->orientation = VERTICAL;
	child->direction = UP;
	child->x = 0;
	child->y = -2;
	ft_lstadd(&list, ft_lstnew(make_move(extremity, child), sizeof(t_move)));
	child->x = -2;
	child->y = 0;
	ft_lstadd(&list, ft_lstnew(make_move(extremity, child), sizeof(t_move)));
	child->x = +2;
	ft_lstadd(&list, ft_lstnew(make_move(extremity, child), sizeof(t_move)));
	child->direction = DOWN;
	ft_lstadd(&list, ft_lstnew(make_move(extremity, child), sizeof(t_move)));
	child->x = -2;
	ft_lstadd(&list, ft_lstnew(make_move(extremity, child), sizeof(t_move)));
	child->x = 0;
	child->y = +2;
	ft_lstadd(&list, ft_lstnew(make_move(extremity, child), sizeof(t_move)));
	child->orientation = HORIZONTAL;
	child->orientation = RIGHT;
	child->y = 0;
	child->x = -2;
	ft_lstadd(&list, ft_lstnew(make_move(extremity, child), sizeof(t_move)));
	child->orientation = LEFT;
	child->y = 0;
	child->x = +2;
	ft_lstadd(&list, ft_lstnew(make_move(extremity, child), sizeof(t_move)));
	return (list);
}
