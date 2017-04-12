/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfetch_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 15:25:35 by aguellil          #+#    #+#             */
/*   Updated: 2016/01/29 01:44:06 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 1. Implementation
*/

/*
** 1.1 Iterative
*/

t_list	*ft_lstfetch_bonus(t_list *lst, size_t n)
{
	size_t	i;

	i = 0;
	while (lst && i < n)
	{
		lst = lst->next;
		i++;
	}
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
**	if (argc == 3)
**	{
**		lst = ft_strtolst_bonus(argv[1]);
**		len_lst = ft_lstlen_bonus(lst);
**		ft_lstprintn_bonus(lst, len_lst);
**		ft_putnbr(ft_atoi(argv[2]));
**		ft_putchar('\n');
**		ft_lstprintn_bonus(ft_lstfetch_bonus(lst, ft_atoi(argv[2])), 1);
**	}
**	return (0);
**}
*/
