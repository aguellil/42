/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 19:47:50 by aguellil          #+#    #+#             */
/*   Updated: 2016/02/04 23:48:36 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** 1. Implementation
*/

/*
** 1.1 Iterative
*/

static void	ft_lstfree_between(t_list *start_link, t_list *end_link)
{
	t_list	*current_link;
	t_list	*next_link;

	current_link = start_link;
	while (current_link && current_link != end_link)
	{
		next_link = current_link->next;
		free(current_link->content);
		free(current_link);
		current_link = next_link;
	}
	if (!current_link)
	{
		free(current_link->content);
		free(current_link);
	}
	current_link = 0;
	return ;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*img_start_link;
	t_list	*img_previous_link;
	t_list	*img_current_link;

	if (!lst)
		return (0);
	img_start_link = (*f)(lst);
	if (!img_start_link)
		return (0);
	img_previous_link = img_start_link;
	lst = lst->next;
	while (lst)
	{
		img_current_link = (*f)(lst);
		if (!img_current_link)
		{
			ft_lstfree_between(img_start_link, img_current_link);
			return (0);
		}
		img_previous_link->next = img_current_link;
		img_previous_link = img_current_link;
		lst = lst->next;
	}
	return (img_start_link);
}
