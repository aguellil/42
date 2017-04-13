/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 00:27:00 by mcanal            #+#    #+#             */
/*   Updated: 2016/04/24 13:57:11 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** create a new hash table
*/

#include "hash.h"

t_htable				*new_table(void)
{
	t_htable	*new;

	new = (t_htable *)malloc(sizeof(t_htable));
	ft_bzero((void *)new, sizeof(t_htable));
	new->bucket = (t_list **)malloc(sizeof(t_list *) * INITIAL_BUCKET_SIZE);
	ft_bzero((void *)new->bucket, sizeof(t_list *) * INITIAL_BUCKET_SIZE);
	new->bucket_size = INITIAL_BUCKET_SIZE;
	return (new);
}
