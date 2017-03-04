/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_possible_moves_vertical.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegroux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 16:22:31 by tlegroux          #+#    #+#             */
/*   Updated: 2017/03/04 18:10:31 by tlegroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domino.h"

t_list	*list_vertical_moves(t_extremity *extremity, t_domino *child)
{
	t_list	*list;

	list = NULL;
	child->orientation = HORIZONTAL;
	child->direction = RIGHT;
	child->y = 0;
	child->x = -1;
	ft_lstadd(&list, ft_lstnew(make_move(extremity, child), sizeof(t_move)));
	child->y = -1;
	child->x = 0;
	ft_lstadd(&list, ft_lstnew(make_move(extremity, child), sizeof(t_move)));
	child->y = +1;
	ft_lstadd(&list, ft_lstnew(make_move(extremity, child), sizeof(t_move)));
	child->direction = LEFT;
	ft_lstadd(&list, ft_lstnew(make_move(extremity, child), sizeof(t_move)));
	child->y = -1;
	ft_lstadd(&list, ft_lstnew(make_move(extremity, child), sizeof(t_move)));
	child->y = 0;
	child->x = +1;
	ft_lstadd(&list, ft_lstnew(make_move(extremity, child), sizeof(t_move)));
	child->orientation = VERTICAL;
	child->orientation = DOWN;
	child->x = 0;
	child->y = -1;
	ft_lstadd(&list, ft_lstnew(make_move(extremity, child), sizeof(t_move)));
	child->orientation = UP;
	child->x = 0;
	child->y = +1;
	ft_lstadd(&list, ft_lstnew(make_move(extremity, child), sizeof(t_move)));
	return (list);
}

t_list	*list_vertical_moves_flipped(t_extremity *extremity, t_domino *child)
{
	t_list	*list;

	list = NULL;
	child->orientation = HORIZONTAL;
	child->direction = LEFT;
	child->y = 0;
	child->x = -2;
	ft_lstadd(&list, ft_lstnew(make_move(extremity, child), sizeof(t_move)));
	child->y = -2;
	child->x = 0;
	ft_lstadd(&list, ft_lstnew(make_move(extremity, child), sizeof(t_move)));
	child->y = +2;
	ft_lstadd(&list, ft_lstnew(make_move(extremity, child), sizeof(t_move)));
	child->direction = RIGHT;
	ft_lstadd(&list, ft_lstnew(make_move(extremity, child), sizeof(t_move)));
	child->y = -2;
	ft_lstadd(&list, ft_lstnew(make_move(extremity, child), sizeof(t_move)));
	child->y = 0;
	child->x = +2;
	ft_lstadd(&list, ft_lstnew(make_move(extremity, child), sizeof(t_move)));
	child->orientation = VERTICAL;
	child->orientation = UP;
	child->x = 0;
	child->y = -2;
	ft_lstadd(&list, ft_lstnew(make_move(extremity, child), sizeof(t_move)));
	child->orientation = DOWN;
	child->x = 0;
	child->y = +2;
	ft_lstadd(&list, ft_lstnew(make_move(extremity, child), sizeof(t_move)));
	return (list);
}
