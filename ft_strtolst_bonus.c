/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolst_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 16:31:41 by aguellil          #+#    #+#             */
/*   Updated: 2016/02/05 02:38:16 by aguellil         ###   ########.fr       */
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

static void		ft_lstfree_between(t_list *start_link, t_list *end_link)
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

static t_list	*ft_chartolnk(char c)
{
	t_list	*lnk;

	if (!c)
		return (0);
	lnk = (t_list *)malloc(1 * sizeof(t_list));
	if (!lnk)
		return (0);
	lnk->content = (char *)malloc(1 * sizeof(char));
	if (!(lnk->content))
	{
		free(lnk);
		return (0);
	}
	*((char *)(lnk->content)) = c;
	lnk->content_size = 1;
	return (lnk);
}

t_list			*ft_strtolst_bonus(char *str)
{
	t_list			*first_link;
	t_list			*previous_link;
	t_list			*current_link;

	first_link = ft_chartolnk(*str);
	if (!first_link)
		return (0);
	current_link = first_link;
	str++;
	while (*str)
	{
		previous_link = current_link;
		current_link = ft_chartolnk(*str);
		if (!current_link)
		{
			ft_lstfree_between(first_link, current_link);
			return (0);
		}
		*((char *)(current_link->content)) = *str;
		current_link->content_size = 1;
		previous_link->next = current_link;
		str++;
	}
	current_link->next = 0;
	return (first_link);
}

/*
** 2. Test
*/

/*
**int				main(int argc, char **argv)
**{
**	t_list	*lst;
**	size_t	len_lst;
***
**	if (argc == 2)
**	{
**		lst = ft_strtolst_bonus(argv[1]);
**		len_lst = ft_lstlen_bonus(lst);
**		ft_lstprintn_bonus(lst, len_lst);
**	}
**	return (0);
**}
*/
