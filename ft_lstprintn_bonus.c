/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprintn_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 00:56:12 by aguellil          #+#    #+#             */
/*   Updated: 2016/01/29 01:14:52 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/*
** 1. Implementation
*/

/*
** 1.1 Iterative
*/

void			ft_lstprintn_bonus(t_list *lst, size_t n)
{
	size_t	i;

	i = 0;
	while (lst && i < n)
	{
		write(1, "[", 1);
		write(1, lst->content, lst->content_size);
		write(1, "]->", 3);
		lst = lst->next;
		i++;
	}
	write(1, "\n", 1);
	return ;
}
