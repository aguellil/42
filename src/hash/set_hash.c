/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hash.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 00:47:12 by mcanal            #+#    #+#             */
/*   Updated: 2016/04/24 17:59:38 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** add a new key/value pair in the table
*/

#include "hash.h"

static void		move_link(t_list **new_bucket, t_list *link, size_t bucket_size)
{
	t_list	**dst;
	t_list	*next;

	while (link)
	{
		next = link->next;
		dst = new_bucket + link->hash % bucket_size;
		link->next = *dst;
		*dst = link;
		link = next;
	}
}

static void		resize_table(t_htable *table)
{
	t_list	**new_bucket;
	t_list	**bucket;
	size_t	size;

	size = table->bucket_size;
	table->bucket_size *= RESIZE_FACTOR;
	new_bucket = (t_list **)malloc(sizeof(t_list *) * table->bucket_size);
	ft_bzero((void *)new_bucket, sizeof(t_list *) * table->bucket_size);
	bucket = table->bucket;
	while (size--)
	{
		if (*bucket)
			move_link(new_bucket, *bucket, table->bucket_size);
		bucket++;
	}
	free(table->bucket);
	table->bucket = new_bucket;
}

static void		add_link(t_list **link, size_t hash, char *key, char *value)
{
	t_list	*swap;

	swap = *link;
	while (swap)
	{
		if (hash == swap->hash && !ft_strcmp(key, swap->key))
		{
			free(swap->value);
			swap->value = value;
			return ;
		}
		swap = swap->next;
	}
	swap = (t_list *)malloc(sizeof(t_list));
	swap->key = key;
	swap->value = value;
	swap->hash = hash;
	swap->next = *link;
	*link = swap;
}

t_bool			set_hash(t_htable *table, char *key, char *value)
{
	size_t	hash;

	if (!*key || !*value)
		return (FALSE);
	hash = jenkins_hash(key);
	add_link(table->bucket + hash % table->bucket_size, hash, key, value);
	table->length++;
	if (table->length / table->bucket_size > RESIZE_TRIGGER)
		resize_table(table);
	return (TRUE);
}
