/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguellil <yguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 03:33:00 by yguellil          #+#    #+#             */
/*   Updated: 2017/01/26 22:30:33 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

void		ft_add_link_to_end(t_tetri **list, t_tetri tetri)
{
	t_tetri		*tmp;
	t_tetri		*last_link;

	if ((tmp = (t_tetri*)malloc(sizeof(t_tetri))) != NULL)
	{
		*tmp = tetri;
		if (*list == NULL)
			*list = tmp;
		else
		{
			last_link = *list;
			while (last_link->next != NULL)
				last_link = last_link->next;
			tmp->next = NULL;
			last_link->next = tmp;
			tmp->prev = last_link;
		}
	}
	else
		ft_launch_error_lst(*list, 1);
	return ;
}

void		ft_lstdel(t_tetri **first)
{
	t_tetri		*next_link;

	while (*first)
	{
		next_link = (*first)->next;
		free(*first);
		*first = next_link;
	}
	*first = NULL;
	return ;
}
