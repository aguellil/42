/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 14:13:28 by mbenjell          #+#    #+#             */
/*   Updated: 2017/04/02 21:47:40 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

void		remove_first(t_list **alist)
{
	t_list	*tmp;

	if (!alist || !*alist)
		return ;
	tmp = *alist;
	*alist = (*alist)->next;
	free(tmp->content);
	free(tmp);
}

void		free_data(t_list *data)
{
	t_row	*row;

	if (!data)
		return ;
	if (data->next)
		free_data(data->next);
	row = (t_row*)data->content;
	free(row);
	free(data);
}
