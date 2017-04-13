/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguellil <yguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 01:41:32 by yguellil          #+#    #+#             */
/*   Updated: 2016/12/12 00:51:16 by yguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void		ft_del_list(t_list *new_list)
{
	t_list		*to_del;

	while (new_list)
	{
		to_del = new_list->next;
		free(new_list);
		new_list = to_del;
	}
	new_list = NULL;
	return ;
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new_list;
	t_list		*link;

	if (!lst || !f)
		return (NULL);
	new_list = (t_list*)malloc(sizeof(*lst));
	if (new_list == NULL)
		return (NULL);
	new_list = (*f)(lst);
	if (new_list == NULL)
		return (NULL);
	link = new_list;
	lst = lst->next;
	while (lst)
	{
		link->next = (*f)(lst);
		if (link->next == NULL)
		{
			ft_del_list(new_list);
			return (NULL);
		}
		link = link->next;
		lst = lst->next;
	}
	return (new_list);
}
