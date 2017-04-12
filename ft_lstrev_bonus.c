/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 15:58:32 by aguellil          #+#    #+#             */
/*   Updated: 2016/01/29 01:29:21 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 1. Implementation
*/

/*
** 1.1  Iterative
*/

t_list	*ft_lstrev_bonus(t_list *lst)
{
	t_list	*previous_link;
	t_list	*current_link;
	t_list	*next_link;

	previous_link = 0;
	while (lst && lst->next)
	{
		current_link = lst;
		next_link = lst->next;
		lst->next = previous_link;
		previous_link = current_link;
		lst = next_link;
	}
	lst->next = previous_link;
	return (lst);
}

/*
** 2. Test
*/

/*
**int		main(int argc, char **argv)
**{
**	t_list	*lst;
**	size_t	len_lst;
***
**	if (argc == 2)
**	{
**		lst = ft_strtolst_bonus(argv[1]);
**		len_lst = ft_lstlen_bonus(lst);
**		ft_lstprintn_bonus(lst, len_lst);
**		ft_lstprintn_bonus(ft_lstrev_bonus(lst), len_lst);
**	}
**	return (0);
**}
*/
