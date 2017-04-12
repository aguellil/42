/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfld_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 16:30:07 by aguellil          #+#    #+#             */
/*   Updated: 2016/02/05 01:33:23 by aguellil         ###   ########.fr       */
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

t_list			*ft_lstfld_bonus(t_list *lst, t_list *(*f)(t_list *, t_list *))
{
	t_list	*relevant_link;
	t_list	*previous_relevant_link;

	relevant_link = (*f)(lst, lst);
	while (lst && lst->next)
	{
		previous_relevant_link = relevant_link;
		relevant_link = (*f)(previous_relevant_link, lst->next);
		free(previous_relevant_link->content);
		free(previous_relevant_link);
		lst = lst->next;
	}
	return (relevant_link);
}

/*
** 2. Test
*/

/*
**static t_list	*ft_lstchar_max(t_list *lnk1, t_list *lnk2)
**{
**	t_list	*link_char_max;
***
**	link_char_max = (t_list *)malloc(1 * sizeof(t_list));
**	if (!link_char_max)
**		return (0);
**	link_char_max->content = (char *)malloc(1 * sizeof(char));
**	if (!(link_char_max->content))
**	{
**		free(link_char_max);
**		return (0);
**	}
**	if (*((char *)(lnk1->content)) > *((char *)(lnk2->content)))
**		*((char *)(link_char_max->content)) = *((char *)(lnk1->content));
**	else
**		*((char *)(link_char_max->content)) = *((char *)(lnk2->content));
**	link_char_max->content_size = 1;
**	return (link_char_max);
**}
***
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
**		ft_lstprintn_bonus(ft_lstfld_bonus(lst, &ft_lstchar_max), 1);
**	}
**	return (0);
**}
*/
