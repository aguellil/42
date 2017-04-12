/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcat_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 15:11:24 by aguellil          #+#    #+#             */
/*   Updated: 2016/01/29 01:50:06 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 1. Implementation
*/

/*
** 1.1 Iterative
*/

t_list	*ft_lstcat_bonus(t_list *lst1, t_list *lst2)
{
	t_list	*first_link;

	if (!lst1)
		first_link = lst2;
	else
	{
		first_link = lst1;
		while (lst1->next)
			lst1 = lst1->next;
		lst1->next = lst2;
	}
	return (first_link);
}

/*
** 2. Test
*/

/*
**int		main(int argc, char **argv)
**{
**	t_list	*lst1;
**	t_list	*lst2;
**	size_t	len_lst1;
**	size_t	len_lst2;
***
**	if (argc == 3)
**	{
**		lst1 = ft_strtolst_bonus(argv[1]);
**		lst2 = ft_strtolst_bonus(argv[2]);
**		len_lst1 = ft_lstlen_bonus(lst1);
**		len_lst2 = ft_lstlen_bonus(lst2);
**		ft_lstprintn_bonus(lst1, len_lst1);
**		ft_lstprintn_bonus(lst2, len_lst2);
**		ft_lstprintn_bonus(ft_lstcat_bonus(lst1, lst2), len_lst1 + len_lst2);
**	}
**	return (0);
**}
*/
