/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 12:34:39 by mcanal            #+#    #+#             */
/*   Updated: 2016/04/24 16:22:57 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** free the hash table and all the bucket elements
*/

#include "hash.h"

static void		del_list(t_list *link)
{
	t_list	*next;

	while (link)
	{
		next = link->next;
		free(link->key);
		free(link->value);
		free(link);
		link = next;
	}
}

void			del_table(t_htable *table)
{
	t_list	**bucket;

	bucket = table->bucket;
	while (table->bucket_size--)
	{
		if (*bucket)
			del_list(*bucket);
		bucket++;
	}
	free(table->bucket);
	free(table);
}
