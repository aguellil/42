/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguellil <yguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 23:28:40 by yguellil          #+#    #+#             */
/*   Updated: 2016/12/12 05:24:09 by yguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*new_link;

	new_link = (t_list*)malloc(sizeof(t_list));
	if (new_link == NULL)
		return (NULL);
	if (!content)
	{
		new_link->content = NULL;
		new_link->content_size = 0;
		new_link->next = NULL;
		return (new_link);
	}
	new_link->content = malloc(content_size);
	if (new_link->content == NULL)
	{
		free(new_link);
		new_link = NULL;
		return (NULL);
	}
	ft_memcpy(new_link->content, content, content_size);
	new_link->content_size = content_size;
	new_link->next = NULL;
	return (new_link);
}
