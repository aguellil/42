/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 18:07:46 by aguellil          #+#    #+#             */
/*   Updated: 2016/02/04 17:47:12 by aguellil         ###   ########.fr       */
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

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list			*p_link;
	int				i;

	p_link = (t_list *)malloc(sizeof(t_list));
	if (!p_link)
		return (0);
	p_link->content = malloc(content_size * sizeof(*content));
	if (!(p_link->content))
	{
		free(p_link);
		p_link = 0;
		return (0);
	}
	if (!content)
	{
		p_link->content = 0;
		p_link->content_size = 0;
		return (p_link);
	}
	i = -1;
	while ((size_t)(++i) < content_size)
		((unsigned char *)(p_link->content))[i] = \
		((unsigned char *)(content))[i];
	p_link->content_size = content_size;
	return (p_link);
}
