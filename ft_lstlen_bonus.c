/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 15:03:31 by aguellil          #+#    #+#             */
/*   Updated: 2016/01/29 01:34:39 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 1. Implementation
*/

/*
** 1.1 Iterative
*/

size_t	ft_lstlen_bonus(t_list *lst)
{
	int	l;

	l = 0;
	while (lst)
	{
		l++;
		lst = lst->next;
	}
	return (l);
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
**		ft_putnbr(len_lst);
**		ft_putchar('\n');
**	}
**	return (0);
**}
*/
